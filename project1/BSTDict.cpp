#ifndef _BSTDICT_CPP
#define _BSTDICT_CPP

//BSTDict.cpp
#include "BSTDict.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// An implementation of a dictionary ADT as a binary search tree
// (without balancing operations).
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
BSTDict<T, Compare>::BSTDict() {
  root = NULL;
}

template <typename T, class Compare>
BSTDict<T, Compare>::~BSTDict() {
  // Ideally, we would recursively traverse the tree to
  // delete all the nodes.  We'd also need to keep track of
  // whether or not to delete the data and key fields, which
  // can be very tricky (are there any other pointers to these
  // fields?)  The newest C++ has so-called smart pointers that
  // will do this for you, but fortunately for us, in our program
  // we never need to delete a dictionary.

  // So, we'll just do nothing in the destructor.
}


template <typename T, class Compare>
bool BSTDict<T, Compare>::find(T key, T &pred) {
  node *current = root;

  // Invariants: 
  // + current points to the subtree in which key either DOES appear or
  //   WOULD appear if it were in the tree.
  // + current is i levels deep in the tree, where the root is at level
  //   0, and i is the iteration number, 0 for the first iteration.  
  //
  // The loop terminates when either current == NULL (so the key must
  // not be in the tree, since the subtree is empty!) or when current
  // points to a node containing key.
  while (current != NULL &&                 // current is not NULL and
	 Compare()(key, current->key) != 0) // current does not contain the key
    {
      // It's a smidge inefficient to calculate this twice,
      // but it seems clearer to make the loop guard above stand alone.
      int compare = Compare()(key, current->key);

      // TODO: correct the following line!  
      // (The right direction isn't always left, as they say.)
      // 
      // Use compare to figure out which subtree
      // the key should be in.  It's NOT in the root.  Inspecting the code
      // below should help!
			current = current->left;
    }

  if (current == NULL) {
    return false;
  }
  else {
    pred = current->data;
    return true;
  }
}

template <typename T, class Compare>
void BSTDict<T, Compare>::add(T key, T pred) {
  // An empty tree is a special case.
  if (root == NULL) {
    root = new node;
    root->key = key;
    root->data = pred;
    root->left = NULL;
    root->right = NULL;
    return;
  }
  
  // Otherwise, we'll work with the start-of-loop invariant: (1) next
  // points a subtree that either contains the key or is where the key
  // would be if it were in the tree; (2) current points to the parent
  // of that subtree (NULL for the root's parent); (3) next is i
  // levels deep in the tree, where the root is at level 0, and i is
  // the iteration number, 0 for the first iteration.  
  //
  // The loop terminates when we either find the node or next is NULL
  // (meaning that empty subtree is where we should insert the new
  // node).
  node *current = NULL;
  node *next = root;
  
  do {
    current = next;
    
    int compare = Compare()(key, current->key);
    if (compare < 0) {
      next = current->left;
    }
    else if (compare > 0) {
      next = current->right;
    }
    else {
      // We found the key (unexpected!).
      // We replace its predecessor and return.
      current->data = pred;
      return;
    }
  } while (next != NULL);
  
  // current is the parent of where the node belongs.  compare tells us
  // whether it's on the right or left.
  assert(Compare()(key, current->key) != 0);

  // Make the new node..
  next = new node;
  next->key = key;
  next->data = pred;
  next->left = NULL;
  next->right = NULL;
  // ..and place it in the tree.
  if (Compare()(key, current->key) < 0) {
    current->left = next;
  }
  else {
    current->right = next;
  }
}

#endif 
