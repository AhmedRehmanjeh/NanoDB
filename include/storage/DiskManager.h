#ifndef DISK_MANAGER_H
#define DISK_MANAGER_H

#include <fstream>
#include <string>
#include "pager/Page.h"

class DiskManager {
private:
    std::string dbFile;
    std::fstream fileStream;

public:
    DiskManager(const std::string& filename);
    ~DiskManager();

    void readPage(int pageId, char* buffer);
    void writePage(int pageId, const char* buffer);
};

#endif
