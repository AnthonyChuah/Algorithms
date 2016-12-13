#include <algorithm>
#include <climits>
#include <array>

#include "graph.h"

Graph::Graph(int _vertices) : v(_vertices), e(0) {
  for (int i = 0; i < _vertices; i++) {
    std::list<std::pair<int, int> > adj_list;
    vertices.push_back(adj_list);
  }
}

bool Graph::addEdge(int _v1, int _v2, int _weight) {
  std::pair<int, int> v1;
  v1.first = _v2;
  v1.second = _weight;
  std::pair<int, int> v2;
  v2.first = _v1;
  v2.second = _weight;
  std::list<std::pair<int, int> >::iterator find_v1 = std::find(vertices[_v1].begin(), vertices[_v1].end(), v1);
  std::list<std::pair<int, int> >::iterator find_v2 = std::find(vertices[_v2].begin(), vertices[_v2].end(), v2);
  bool overwrote = false;
  if (find_v1 != vertices[_v1].end()) {
    vertices[_v1].erase(find_v1);
    overwrote = true;
  }
  if (find_v2 != vertices[_v2].end()) {
    vertices[_v2].erase(find_v2);
    overwrote = true;
  }
  vertices[_v1].push_back(v1);
  vertices[_v2].push_back(v2);
  if (!overwrote) {
    e++;
  }
  return overwrote;
}

std::vector<std::pair<int, int> > Graph::adj(int _v) {
  std::vector<std::pair<int, int> > neighbours;
  for (std::list<std::pair<int, int> >::iterator it = vertices[_v].begin(); it != vertices[_v].end(); it++) {
    neighbours.push_back(*it);
  }
  return neighbours;
}

int Graph::getVertices() { return v; }
int Graph::getEdges() { return e; }

std::vector<int> Graph::pathfinder(int _from, int _to) {
  std::vector<int> shortestpath;
  std::vector<std::vector<int> > pathweights;
  std::vector<std::vector<bool> > minweights;
  std::vector<int> minselects;
  minselects.push_back(_from);
  std::vector<bool> firstrow_bool;
  firstrow_bool.push_back(true);
  firstrow_bool.resize(v, false);
  std::vector<int> firstrow_weights;
  firstrow_weights.push_back(0);
  firstrow_weights.resize(v, INT_MAX);
  pathweights.push_back(firstrow_weights);
  minweights.push_back(firstrow_bool);
  while (true) {
    // Fetch the neighbours and weights of the _from vertex.
    
  }
  return shortestpath;
}
