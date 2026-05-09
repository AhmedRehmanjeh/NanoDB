#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "storage/CustomVector.h"
#include "storage/Value.h"

struct Column {
    std::string name;
    DataType type;
};

class BufferPool;

class Table {
public:
    std::string name;
    CustomVector<Column> columns;
    BufferPool* bufferPool;

    Table(const std::string& n, BufferPool* bp);

    void addColumn(const std::string& colName, DataType type);
    int getColumnIndex(const std::string& colName) const;
};

#endif
