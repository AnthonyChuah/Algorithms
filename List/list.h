struct Node;

struct Node {
  int data;
  Node* next;
};

class List {
 public:
  List();
  void print();
  void headInsert(int _data);
  void deleteByData(int _data);
  void headDelete();
  // void reverse();
 private:
  Node* head;
};
