//LinkedListDict.hpp
#ifndef _LINKEDLISTDICT_HPP
#define _LINKEDLISTDICT_HPP

#include "Compare.hpp"
#include "PredDict.hpp"

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

// An implementation of a dictionary ADT as an unsorted linked list.
// This will be very slow.
//
// the template type means that the dictionary will store elements
// with key type T, and data type T; and two elements of type T
// will be compared using the operator() of a Compare class.

template <typename T, class Compare>
  class LinkedListDict : public PredDict<T>
  {
  public:
    LinkedListDict();
    ~LinkedListDict();
    bool find(T key, T &pred);
    void add(T key, T pred);

  private:
    struct node {
      T key;
      T data;
      node *next;
    };

    node *root;

    bool find_helper(node *r, T key, T &pred);
  };

#include "LinkedListDict.cpp"

#endif

