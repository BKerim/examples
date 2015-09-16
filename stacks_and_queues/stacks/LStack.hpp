#ifndef LSTACK_HPP
#define LSTACK_HPP

#include <cassert>
#include "Stack.hpp"

template <class T>
struct LStack_Node {
  T data;
  LStack_Node* next = 0;
  LStack_Node(const T& t) { data = t; }
};

template <class T>
class LStack : public Stack<T> {
private:
  // the current number of items in the list
  int current_size = 0;

  // a pointer to the top of the stack
  LStack_Node<T>* top = 0;

public:
  // constructor
  LStack() {}
  ~LStack();
  
  void push(const T&);
  T pop();
  const T& peek() const;
  void clear() { while(current_size > 0) { pop(); } }
  int size() { return current_size; }
};

template <class T>
LStack<T>::~LStack() {
  // this will remove all of the objects created on the heap
  clear();
}  

template <class T>
void LStack<T>::push(const T& t) {

  // make a new node and add t to it
  LStack_Node<T>* lsn = new LStack_Node<T>(t);

  // add the node to the linked list
  lsn->next = top;
  top = lsn;
  ++current_size;
}

template <class T>
T LStack<T>::pop() {
  // make sure the list is not empty
  assert(current_size > 0);

  LStack_Node<T>* temp = top;
  top = top->next;
  T t = temp->data;
  delete temp;
  --current_size;
  return t;
}

template <class T>
const T& LStack<T>::peek() const {
  // make sure the list is not empty
  assert(current_size > 0);

  // return the top item data without remove it
  return top->data;
}

#endif
