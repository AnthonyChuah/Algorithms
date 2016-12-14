#include <iostream>
#include <cstddef>

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
  int getMax(); // Gets the max value.
private:
  std::vector<int> heap;
  void exch(int i, int j);
  void swim(int k);
  void sink(int k);
  void heapify();
};

MaxHeap::MaxHeap() : {
  heap.push_back(0);
}
MaxHeap::MaxHeap(const std::vector<int>& _keys) {
  heap.push_back(0);
  for (int i = 0; i < _keys.size(); i++) {
    heap.push_back(_keys[i]);
  }
}
void MaxHeap::insert(int _key) {
  heap.push_back(_key);
  swim(heap.size() - 1);
}
int MaxHeap::max() { return heap[1]; }
int MaxHeap::eraseMax() {
  int max = heap[1];
  exch(1, heap.size() - 1);
  heap.pop_back();
  sink(1);
  return max;
}
void MaxHeap::exch(int i, int j) {
  int temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}
void MaxHeap::swim(int k) {
  while (k > 1 && heap[k] > heap[k/2]) {
    exch(k, k/2);
    k /= 2;
  }
}
void MaxHeap::sink(int k) {
  while (2*k <= heap.size() - 1) {
    int j = 2*k; // Select the left child index.
    if (j < (heap.size() - 1) && heap[j] < heap[j+1]) j++; // If left less than right, select right child index.
    if (heap[k] > heap[j]) break; // Heap property is satisfied, stop sinking.
    else {
      exch(k, j); // Swap values at index k and j.
      k = j;
    }
  }
}
void MaxHeap::heapify() {
  for (int i = heap.size() - 1; i >= 0; i--) {
    sink(i);
  }
}
int MaxHeap::getMax() {
  return heap[1];
}
