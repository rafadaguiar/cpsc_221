//BSTDict.hpp
#ifndef _BSTDICT_HPP
#define _BSTDICT_HPP

#include "Compare.hpp"
#include "PredDict.hpp"

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

// An implementation of a dictionary ADT as a binary search tree
// (without balancing operations).
//
// the template type means that the dictionary will store elements
// with key type T, and data type T; and two elements of type T
// will be compared using the operator() of a Compare class.

template <typename T, class Compare>
  class BSTDict : public PredDict<T>
  {
  public:
    BSTDict();
    ~BSTDict();
    bool find(T key, T &pred);
    void add(T key, T pred);

  private:
    struct node {
      T key;
      T data;
      node *left;
      node *right;
    };

    node *root;
  };

#include "BSTDict.cpp"

#endif

