#ifndef PAGE_H
#define PAGE_H

#include <cstring>

const size_t PAGE_SIZE = 4096; // 4KB pages

class Page {
public:
    char data[PAGE_SIZE];
    int pageId;
    bool isDirty;
    int pinCount;

    Page() : pageId(-1), isDirty(false), pinCount(0) {
        std::memset(data, 0, PAGE_SIZE);
    }

    void reset() {
        pageId = -1;
        isDirty = false;
        pinCount = 0;
        std::memset(data, 0, PAGE_SIZE);
    }
};

#endif
