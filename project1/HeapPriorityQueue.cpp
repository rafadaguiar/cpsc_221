//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

template <typename T, class Compare>
HeapPriorityQueue<T, Compare>::HeapPriorityQueue() {
  // TODO: implement constructor
}

template <typename T, class Compare>
HeapPriorityQueue<T, Compare>::~HeapPriorityQueue() {
  // TODO: implement destructor
}

template <typename T, class Compare>
void HeapPriorityQueue<T, Compare>::add(T /*elem*/) {
  // TODO: uncomment parameter name (commented out so you don't get a warning)
  // TODO: implement add
}

template <typename T, class Compare>
T HeapPriorityQueue<T, Compare>::remove() {
  return (T)0;
  // TODO: implement remove
}


template <typename T, class Compare>
T HeapPriorityQueue<T, Compare>::get_next() {
  return (T)0;
  // TODO: implement get_next
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::size() {
  return 0;
  // TODO: implement size
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::parent(int index) {
  return 0;
  // TODO: implement the parent helper function
  // give back index's parent
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::first_child(int index) {
  return 0;
  // TODO: implement first_child helper function
  // give back the the first (left) child of index
}

template <typename T, class Compare>
bool HeapPriorityQueue<T, Compare>::is_root(int index) {
  return false;
  // TODO: implement is_root helper function
  // true iff index is the root of the heap
}

template <typename T, class Compare>
bool HeapPriorityQueue<T, Compare>::is_leaf(int index) {
  return false;
  // TODO: implement is_leaf helper function
  // true iff index is a leaf (no children) in the heap
  // hint: easy to implement by using num_children!
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::num_children(int index) {
  return 0;
  // TODO: implement num_children helper function
  // gives back the number of children index has (0, 1, or 2)
}

#endif
