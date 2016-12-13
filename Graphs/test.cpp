#include <iostream>

#include "graph.h"

int main() {
  std::cout << "Testing the Graph class, an undirected weighted graph.\n";
  Graph newgraph(6);
  newgraph.addEdge(0, 1, 4);
  newgraph.addEdge(0, 2, 2);
  newgraph.addEdge(1, 2, 1);
  newgraph.addEdge(1, 3, 5);
  newgraph.addEdge(2, 3, 8);
  newgraph.addEdge(2, 4, 10);
  newgraph.addEdge(3, 4, 2);
  newgraph.addEdge(3, 5, 6);
  newgraph.addEdge(4, 5, 3);
  std::cout << "This Graph should have 6 vertices and 9 edges.\n";
  std::cout << "Vertices: " << newgraph.getVertices() << "  Edges: " << newgraph.getEdges() << "\n";
  std::cout << "Vertex 2 should have 4 neighbours, 0 1 3 4.\n";
  std::vector<std::pair<int, int> > v2adj = newgraph.adj(2);
  for (std::vector<std::pair<int, int> >::iterator it = v2adj.begin(); it != v2adj.end(); it++) {
    std::cout << it->first << " " << it->second << "  ";
  }
  std::vector<int> dijkstra;
  dijkstra = newgraph.pathfinder(0, 5);
  return 0;
}
