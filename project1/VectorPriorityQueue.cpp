#ifndef _VECTORPRIORITYQUEUE_CPP
#define _VECTORPRIORITYQUEUE_CPP

//VectorPriorityQueue.cpp
#include "VectorPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// A naive implementation of a priority queue, using
// a vector and searching for the max for each add
// and remove operation
//
// the template type means that the priority queue
// will store elements of type T, and two elements
// of type T will be compared using operator() of
// a Compare class, which we will use as
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
VectorPriorityQueue<T, Compare>::VectorPriorityQueue() {
  // empty, no allocation
}

template <typename T, class Compare>
VectorPriorityQueue<T, Compare>::~VectorPriorityQueue() {
  // no clean-up to do, since list is not dynamically allocated
}

template <typename T, class Compare>
void VectorPriorityQueue<T, Compare>::add(T elem) {
  list.push_back(elem);
}

template <typename T, class Compare>
T VectorPriorityQueue<T, Compare>::remove() {
  if (list.size() < 1)
    return (T)NULL;

  int min_index = 0;
  for (int i = 0; i < (int)list.size(); i++) {
    // use the () operator for comparison:
    // since we're keeping the minimum, we
    // want to see if it's > 0 in order to
    // to see if list[i] is greater than list[min_index]
    if (Compare() (list[i], list[min_index]) < 0)
      min_index = i;
  }

  T ret = list[min_index];
  list.erase(list.begin() + min_index); // remove list[min_index]
  return ret;
}


template <typename T, class Compare>
T VectorPriorityQueue<T, Compare>::get_next() {
  if (list.size() < 1)
    return (T)NULL;

  int min_index = 0;
  for (int i = 0; i < (int)list.size(); i++) {
    if (Compare() (list[i], list[min_index]) < 0)
      min_index = i;
  }

  T ret = list[min_index];
  return ret;
}

template <typename T, class Compare>
int VectorPriorityQueue<T, Compare>::size() {
  return list.size();
}

#endif 
