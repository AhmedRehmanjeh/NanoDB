#include "storage/Table.h"

Table::Table(const std::string& n, BufferPool* bp) : name(n), bufferPool(bp) {}

void Table::addColumn(const std::string& colName, DataType type) {
    columns.push_back({colName, type});
}

int Table::getColumnIndex(const std::string& colName) const {
    for (size_t i = 0; i < columns.getSize(); ++i) {
        if (columns[i].name == colName) return i;
    }
    return -1;
}
