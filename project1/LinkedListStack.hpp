//LinkedListStack.hpp
#ifndef _LINKEDLISTSTACK_HPP
#define _LINKEDLISTSTACK_HPP

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

#include "TodoList.hpp"


// TODO: declare a templated LinkedListStack that extends TodoList.
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

    //static const int INIT_SIZE = 5;

    private:
      // A helper function that consumes a number and ensures the queue
      // has enough space for that many elements.  (In C++, it might be
      // better style--and functionality--to make the argument (and all 
      // of our parameters) unsigned ints rather than ints.. but things
      // are complex enough for this assignment!
      
      //void ensure_capacity(int n);

      // a pointer to the underlying list with elements of type T
      struct node{
        node * next;
        T val;
      };
      node * root;
};

#include "LinkedListStack.cpp"

#endif
