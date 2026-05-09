#ifndef BUFFER_POOL_H
#define BUFFER_POOL_H

#include "pager/Page.h"
#include "storage/DiskManager.h"
#include "pager/LRUCache.h"
#include "hashmap/CustomHashMap.h"
#include "logger/Logger.h"

class BufferPool {
private:
    Page* pages;
    size_t capacity;
    DiskManager* diskManager;
    LRUCache lru;
    CustomHashMap<int, int> pageMap; // pageId -> frameIndex
    int nextFreeFrame;

public:
    BufferPool(size_t cap, DiskManager* dm);
    ~BufferPool();

    Page* getPage(int pageId);
    void flushAll();
};

#endif
