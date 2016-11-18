#include <cstddef>
#include <iostream>
#include <fstream>
#include <climits>

class Node;
// Forward-declaration of a node.

class Node
{
public:
  Node(int _key, int _value, Node* _next); // Constructor.
  int getKey() const; // Getter for key.
  void setKey(int _key); // Setter for key.
  int getValue() const; // Getter for value.
  void setValue(int _value); // Setter for value.
  Node* getNext() const; // Getter for next node.
  void setNext(Node* _next); // Sets Node* as the next Node.
private:
  int key;
  int value;
  Node* next;
};

Node::Node(int _key, int _value, Node* _next) {
  key = _key;
  value = _value;
  next = _next;
}

int Node::getKey() const { return key; }

void Node::setKey(int _key) { key = _key; }

int Node::getValue() const { return value; }

void Node::setValue(int _value) { value = _value; }

Node* Node::getNext() const { return next; }

void Node::setNext(Node* _next) { next = _next; }

typedef Node* NodePtr;

class LinkedList
{
public:
  LinkedList();
  void insert(int _key, int _value);
  void erase(int _key);
  int lookup(int _key);
  friend std::ostream& operator <<(std::ostream& outs, LinkedList object);
private:
  NodePtr head;
};

LinkedList::LinkedList() : head(NULL) {}

void LinkedList::insert(int _key, int _value) {
  NodePtr finder;
  finder = head;
  while (finder != NULL) {
    if (finder->getKey() == _key) {
      finder->setValue(_value);
      return;
    } else {
      finder = finder->getNext();
    }
  } // If you have not yet returned after this, the LList does not contain the key.
  NodePtr newhead;
  newhead = new Node(_key, _value, NULL);
  newhead->setNext(head);
  head = newhead;
}

void LinkedList::erase(int _key) {
  NodePtr erased, prev;
  erased = head;
  prev = NULL;
  while (erased != NULL && erased->getKey() != _key) {
    prev = erased;
    erased = erased->getNext();
  } // When this breaks, either erased is at the NULL end and prev is at the end, or erased has found the key.
  if (erased == NULL) {
    return;
  } // This also covers the case when the LL is empty.
  // Handle the case of the head node being NULL.
  if (prev == NULL) {
    prev = erased;
    head = head->getNext();
    delete prev;
  }
  // If it wasn't the head node, use prev to delete the node.
  if (erased->getKey() == _key) {
    prev->setNext(erased->getNext());
    delete erased;
  } // Else, you have found nothing to erase. Do nothing.
}

int LinkedList::lookup(int _key) {
  NodePtr finder;
  finder = head;
  while (finder != NULL) {
    if (finder->getKey() == _key) {
      return finder->getValue();
    }
    finder = finder->getNext();
  }
  return INT_MIN;
}

std::ostream& operator <<(std::ostream& outs, LinkedList object) {
  NodePtr traverse;
  traverse = object.head;
  while (traverse != NULL) {
    outs << traverse->getValue() << " ";
    traverse = traverse->getNext();
  }
  return outs;
}

int main() {
  LinkedList list;
  std::cout << "Testing LinkedList with key-value lookup.\n";
  std::cout << "Please enter a stream of integers, and use a negative number to end the input.\n";
  int input; int key = 0;
  while (std::cin >> input) {
    if (input < 0) break;
    list.insert(key, input);
    key++;
  }
  std::cout << "Entered " << key << " values.\n";
  std::cout << "Testing the print function.\n";
  std::cout << list;
  std::cout << "Testing insertion at key == 0, which should overwrite the value. Let's say value is 0.\n";
  list.insert(0, 0);
  std::cout << list;
  std::cout << "Testing lookup of key == 5, if it exists returns value, if not returns int_min.\n";
  std::cout << "Lookup: " << list.lookup(5) << "\n";
  std::cout << "Testing erase at key == 0.\n";
  list.erase(0);
  std::cout << list;
  std::cout << "Testing erase at key == 5.\n";
  list.erase(5);
  std::cout << list;
  return 0;
}
