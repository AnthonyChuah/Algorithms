#include <cstddef>
#include <iostream>

#include "list.h"

List::List() : head(NULL) {}

void List::print() {
  for (Node* i = head; i != NULL; i = i->next) {
    std::cout << i->data << " ";
  }
  std::cout << '\n';
}

void List::headInsert(int _data) {
  Node* newHead;
  newHead = new Node;
  newHead->data = _data;
  newHead->next = head;
  head = newHead;
}

void List::headDelete() {
  Node* tempPtr;
  tempPtr = new Node;
  tempPtr = head;
  head = head->next;
  delete tempPtr;
}

void List::deleteByData(int _data) {
  Node* prev;
  prev = NULL;
  Node* i;
  for (i = head; i != NULL; i = i->next) {
    if (i->data == _data) break;
    prev = i;
  }
  if (i != NULL) {
    if (prev != NULL) {
      prev->next = i->next;
    }
    delete i;
  }
}
