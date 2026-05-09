#ifndef LOADER_H
#define LOADER_H

#include <fstream>
#include <sstream>
#include <string>
#include "storage/Table.h"

class Loader {
public:
    static void loadTable(Table& table, const std::string& filename, int maxRows);
};

#endif
