#include "storage/DiskManager.h"

DiskManager::DiskManager(const std::string& filename) : dbFile(filename) {
    fileStream.open(dbFile, std::ios::binary | std::ios::in | std::ios::out);
    if (!fileStream.is_open()) {
        // Create the file if it doesn't exist
        fileStream.open(dbFile, std::ios::binary | std::ios::out);
        fileStream.close();
        fileStream.open(dbFile, std::ios::binary | std::ios::in | std::ios::out);
    }
}

DiskManager::~DiskManager() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

void DiskManager::readPage(int pageId, char* buffer) {
    fileStream.clear();
    fileStream.seekg(pageId * PAGE_SIZE);
    fileStream.read(buffer, PAGE_SIZE);
}

void DiskManager::writePage(int pageId, const char* buffer) {
    fileStream.clear();
    fileStream.seekp(pageId * PAGE_SIZE);
    fileStream.write(buffer, PAGE_SIZE);
    fileStream.flush();
}
