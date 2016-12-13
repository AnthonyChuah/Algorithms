#include <iostream>
#include <cstddef>

class TreeNode;

class TreeNode {
public:
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  int key;
};

class MaxHeap {
public:
  MaxHeap(); // Create empty heap.
  MaxHeap(int _size); // Create heap of give size.
  MaxHeap(const std::vector<int>& _keys); // Create heap from vector of keys.
  void insert(int _key); // Insert a key into the heap.
  int max(); // Returns the largest key.
  int eraseMax(); // Returns and removes the largest key.
  bool isEmpty(); // Checks if heap is empty.
  int size(); // Returns size of the heap.
  void insert(int _key); // Inserts a new element.
private:
  std::vector<int> heap;
  int size;
  void exch(int i, int j);
  void swim(int k);
  void sink(int k);
};

MaxHeap::MaxHeap() : size(1) {
  heap.push_back(0);
}
MaxHeap::MaxHeap(int _size) : size(_size) {
  heap.resize(_size+1); // Check syntax for resizing vector.
}
MaxHeap::MaxHeap(const std::vector<int>& _keys) {
  for (int i = 0; i < _keys.size(); i++) {
    heap.push_back(_keys[i]);
  }
  size = heap.size();
}
void MaxHeap::insert(int _key) {
  heap.push_back(_key);
  size++;
  swim(size);
}
int MaxHeap::max() { return heap[1]; }
int MaxHeap::eraseMax() {
  int max = heap[1];
  exch(1, size--);
  heap.pop_back();
  sink(1);
  return max;
}
