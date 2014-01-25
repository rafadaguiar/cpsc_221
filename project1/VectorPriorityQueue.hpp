//VectorPriorityQueue.hpp
#ifndef _VECTORPRIORITYQUEUE_HPP
#define _VECTORPRIORITYQUEUE_HPP

#include <vector>
#include "Compare.hpp"
#include "TodoList.hpp"

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

// A naive implementation of a priority queue, using a vector and
// searching for the max for each add and remove operation
//
// the template type means that the priority queue will store elements
// of type T, and two elements of type T will be compared using
// operator() of a Compare class.
template <typename T, class Compare>
  class VectorPriorityQueue : public TodoList<T>
  {
  public:
    VectorPriorityQueue();
    T remove();
    void add(T element);
    T get_next();
    int size();
    ~VectorPriorityQueue();

  private:
    vector<T> list;
  };

#include "VectorPriorityQueue.cpp"

#endif

