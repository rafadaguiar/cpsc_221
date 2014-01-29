#ifndef _LINKEDLISTDICT_CPP
#define _LINKEDLISTDICT_CPP

//LinkedListDict.cpp
#include "LinkedListDict.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// An implementation of a dictionary ADT as an unsorted linked list.
//
// the template type means that the dictionary will store elements
// with key type T, and data type T; and two elements of type T
// will be compared using the operator() of a Compare class.
//
// Compare() (elem1, elem2), which will return a
// number > 0 if elem1 is greater than elem2,
// 0 if elem1 is equal to elem2, and < 0 if elem1
// is less than elem2. Note that this will NOT give
// the same result as directly comparing elem1 and
// elem2 as "elem1 > elem2" as it does not correspond
// to any overloaded operator>, operator==, or
// operator< defined by the type.

template <typename T, class Compare>
LinkedListDict<T, Compare>::LinkedListDict() {
  root = NULL;
}

template <typename T, class Compare>
LinkedListDict<T, Compare>::~LinkedListDict() {
  // Ideally, we would recursively traverse the list to
  // delete all the nodes.  We'd also need to keep track of
  // whether or not to delete the data and key fields, which
  // can be very tricky (are there any other pointers to these
  // fields?)  The newest C++ has so-called smart pointers that
  // will do this for you, but fortunately for us, in our program
  // we never need to delete a dictionary.

  // So, we'll just do nothing in the destructor.
}

template <typename T, class Compare>
bool LinkedListDict<T, Compare>::find_helper(node *r, T key, T &pred) {
  if (r==NULL) return false; // Never found it.
  int compare = Compare()(key, r->key);
  if (compare == 0) {
    pred = r->data; // Got it!  Get the result.
    return true;
  }
  return find_helper(r->next, key, pred);
}

template <typename T, class Compare>
bool LinkedListDict<T, Compare>::find(T key, T &pred) {
  return find_helper(root, key, pred);
}

template <typename T, class Compare>
void LinkedListDict<T, Compare>::add(T key, T pred) {
  node * temp = new node();
  temp->key = key;
  temp->data = pred;
  temp->next = root;
  root = temp;
  return;
}

#endif 
