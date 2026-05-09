#include "optimizer/JoinOptimizer.h"

CustomVector<Edge> JoinOptimizer::findMST(int numNodes,
                                          CustomVector<Edge> &edges) {
  // Sort edges by weight
  for (size_t i = 0; i < edges.getSize(); ++i) {
    for (size_t j = 0; j < edges.getSize() - i - 1; ++j) {
      if (edges[j].weight > edges[j + 1].weight) {
        Edge temp = edges[j];
        edges[j] = edges[j + 1];
        edges[j + 1] = temp;
      }
    }
  }

  CustomVector<Edge> mst;
  int *parent = new int[numNodes];
  for (int i = 0; i < numNodes; ++i)
    parent[i] = i;
  auto find = [&](int i) -> int {
    int curr = i;
    while (parent[curr] != curr) {
      parent[curr] = parent[parent[curr]]; // Path compression
      curr = parent[curr];
    }
    return curr;
  };

  for (size_t i = 0; i < edges.getSize(); ++i) {
    int x = find(edges[i].src);
    int y = find(edges[i].dest);

    if (x != y) {
      mst.push_back(edges[i]);
      parent[x] = y;
    }
  }
  delete[] parent;

  // Log MST path
  std::string path = "Multi-table join routed via MST: ";
  for (size_t i = 0; i < mst.getSize(); ++i) {
    path += std::to_string(mst[i].src) + " -> " + std::to_string(mst[i].dest) +
            (i == mst.getSize() - 1 ? "" : ", ");
  }
  globalLogger.log(path);

  return mst;
}
