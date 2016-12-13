#include <iostream>

#include "list.h"

int main() {
  List list;
  list.headInsert(1);
  list.headInsert(2);
  list.headInsert(3);
  list.headInsert(4);
  list.headInsert(5);
  list.print();
  list.headDelete();
  list.print();
  list.deleteByData(6);
  list.print();
  list.deleteByData(3);
  list.print();
  list.deleteByData(4);
  list.print();
  list.deleteByData(1);
  list.print();
  return 0;
}
