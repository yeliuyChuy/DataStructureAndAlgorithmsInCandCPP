#include "BFS_DFS.h"

int main() {
  int G[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0},
                 {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0},
                 {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0, 0}};
  DFS(G, 4, 7);

  return 0;
}