//ArrayStack.hpp
#ifndef _ARRAYSTACK_HPP
#define _ARRAYSTACK_HPP

#include "TodoList.hpp"

// 221 STUDENTS:
//
// This complete array stack implementation is
// here to help get you started.
template <typename T>
class ArrayStack: public TodoList<T>
{
public:
  ArrayStack(); // constructor - DO NOT CHANGE SIGNATURE!
  
  // TodoList interface
  void add(T elem);
  T remove();
  T get_next();
  int size();

  ~ArrayStack(); // destructor

  static const int INIT_SIZE = 5;

private:
  // A helper function that consumes a number and ensures the queue
  // has enough space for that many elements.  (In C++, it might be
  // better style--and functionality--to make the argument (and all 
  // of our parameters) unsigned ints rather than ints.. but things
  // are complex enough for this assignment!
  void ensure_capacity(int n);

  // a pointer to the underlying array with elements of type T
  T * array;

  // the index of the element currently the top element of the ArrayStack
  int top;

  // how many elements the stack is capable of holding in the underlying array
  int capacity;
};

#include "ArrayStack.cpp"

#endif
