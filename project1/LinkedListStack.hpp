//LinkedListStack.hpp
#ifndef _LINKEDLISTSTACK_HPP
#define _LINKEDLISTSTACK_HPP

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

#include "TodoList.hpp"


// declare a templated LinkedListStack that extends TodoList.
//
template <typename T>
class LinkedListStack: public TodoList<T>{
    public:
      LinkedListStack();
      void add(T elem);
      T remove();
      T get_next();
      int size();
      virtual ~LinkedListStack();

    private:
      // a pointer to the underlying list with elements of type T
      struct node{
        node * next;
        T val;
      };
      node * root;
};

#include "LinkedListStack.cpp"

#endif
