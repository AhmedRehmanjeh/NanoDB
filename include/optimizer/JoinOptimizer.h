#ifndef JOIN_OPTIMIZER_H
#define JOIN_OPTIMIZER_H

#include "storage/CustomVector.h"
#include "logger/Logger.h"
#include <string>

struct Edge {
    int src, dest, weight;
};

class JoinOptimizer {
public:
    static CustomVector<Edge> findMST(int numNodes, CustomVector<Edge>& edges);
};

#endif
