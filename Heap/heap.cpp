#include <iostream>
#include <cstddef>
#include <vector>

class MaxHeap {
public:
  MaxHeap(); // Create empty heap.
  MaxHeap(int _size); // Create heap of give size.
  MaxHeap(const std::vector<int>& _keys); // Create heap from vector of keys.
  void insert(int _key); // Insert a key into the heap.
  int eraseMax(); // Returns and removes the largest key.
  bool isEmpty(); // Checks if heap is empty.
  int size(); // Returns size of the heap.
  int getMax(); // Gets the max value.
  void print(); // Prints the elements of the heap in vector order.
  // private:
  std::vector<int> heap;
  void exch(int i, int j);
  void swim(int k);
  void sink(int k);
  void heapify();
};

MaxHeap::MaxHeap() {
  heap.push_back(0);
}
MaxHeap::MaxHeap(const std::vector<int>& _keys) {
  heap.push_back(0);
  int size = _keys.size();
  for (int i = 0; i < size; i++) {
    heap.push_back(_keys[i]);
  }
}
void MaxHeap::insert(int _key) {
  heap.push_back(_key);
  swim(heap.size() - 1);
}
int MaxHeap::eraseMax() {
  int max = heap[1];
  exch(1, heap.size() - 1);
  heap.pop_back();
  sink(1);
  return max;
}
void MaxHeap::print() {
  int size = heap.size();
  // Skip the dummy number at index 0: it is always 0.
  for (int i = 1; i < size; i++) {
    std::cout << heap[i] << " ";
  }
  std::cout << "\n";
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
  int size = heap.size();
  while (2*k <= size - 1) {
    int j = 2*k; // Select the left child index.
    if (j < (size - 1) && heap[j] < heap[j+1]) j++; // If left less than right, select right child index.
    if (heap[k] > heap[j]) break; // Heap property is satisfied, stop sinking.
    else {
      exch(k, j); // Swap values at index k and j.
      k = j;
    }
  }
}
void MaxHeap::heapify() {
  int size = heap.size();
  for (int i = size - 1; i >= 1; i--) {
    sink(i);
  }
}
int MaxHeap::getMax() {
  return heap[1];
}

int main() {
  MaxHeap testHeap;
  testHeap.insert(5);
  testHeap.insert(-2);
  testHeap.insert(7);
  testHeap.insert(10);
  testHeap.insert(15);
  testHeap.insert(0);
  testHeap.insert(9);
  testHeap.print();
  testHeap.heapify();
  testHeap.print();
  testHeap.insert(20);
  testHeap.print();
  testHeap.eraseMax();
  testHeap.print();
  std::cout << testHeap.getMax() << "\n";
}
