#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <utility>

struct Edge {
int to;
int weight;
};

class Graph {
 public:
  Graph(int _vertices); // Creates a graph with _ number of vertices.
  bool addEdge(int _v1, int _v2, int _weight); // Adds an edge between two vertices. Returns true if it overwrites.
  std::vector<std::pair<int, int> > adj(int _v); // Gets the adjacent vertices for a given vertex.
  int getVertices(); // Gets number of vertices.
  int getEdges(); // Gets number of edges.
  std::vector<int> pathfinder(int _from, int _to); // Finds the path with minimum sum of weights of edges crossed.
 private:
  int v; // Number of vertices.
  int e; // Number of edges.
  std::vector<std::list<std::pair<int, int> > > vertices; // Adjacency-list of pairs<vertex, weight>.
};

#endif
