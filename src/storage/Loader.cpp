#include "storage/Loader.h"
#include <iostream>

void Loader::loadTable(Table& table, const std::string& filename, int maxRows) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;
    int rowCount = 0;
    while (std::getline(file, line) && rowCount < maxRows) {
        std::stringstream ss(line);
        std::string item;
        int colIdx = 0;
        while (std::getline(ss, item, '|') && colIdx < (int)table.columns.getSize()) {
            colIdx++;
        }
        rowCount++;
    }
    file.close();
}
