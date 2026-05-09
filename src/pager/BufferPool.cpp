#include "pager/BufferPool.h"

BufferPool::BufferPool(size_t cap, DiskManager* dm) 
    : capacity(cap), diskManager(dm), lru(cap), nextFreeFrame(0) {
    pages = new Page[capacity];
}

BufferPool::~BufferPool() {
    flushAll();
    delete[] pages;
}

Page* BufferPool::getPage(int pageId) {
    int frameIndex;
    if (pageMap.get(pageId, frameIndex)) {
        lru.refer(pageId);
        return &pages[frameIndex];
    }

    // Page not in memory
    if (nextFreeFrame < capacity) {
        frameIndex = nextFreeFrame++;
    } else {
        // Need to evict
        int evictedPageId = lru.evict();
        pageMap.get(evictedPageId, frameIndex);
        if (pages[frameIndex].isDirty) {
            diskManager->writePage(evictedPageId, pages[frameIndex].data);
        }
        globalLogger.log("Page " + std::to_string(evictedPageId) + " evicted via LRU, written to disk.");
        pageMap.remove(evictedPageId);
    }

    pages[frameIndex].reset();
    diskManager->readPage(pageId, pages[frameIndex].data);
    pages[frameIndex].pageId = pageId;
    pageMap.put(pageId, frameIndex);
    lru.refer(pageId);

    return &pages[frameIndex];
}

void BufferPool::flushAll() {
    for (size_t i = 0; i < capacity; ++i) {
        if (pages[i].pageId != -1 && pages[i].isDirty) {
            diskManager->writePage(pages[i].pageId, pages[i].data);
            pages[i].isDirty = false;
        }
    }
}
