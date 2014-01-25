//LinkedListQueue.hpp
#ifndef _LINKEDLISTQUEUE_HPP
#define _LINKEDLISTQUEUE_HPP

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

#include "TodoList.hpp"

template <typename T>
class LinkedListQueue: public TodoList<T>
{
 public:
  LinkedListQueue();
  void add(T elem);
  T remove();
  T get_next();
  int size();
  virtual ~LinkedListQueue();

 private:
  struct node{
    node* next;
    T data;
  };
    
  node* head;
  node* tail;
  int _size; // The underscore is to avoid a name conflict with the method size
};

#include "LinkedListQueue.cpp"

#endif
