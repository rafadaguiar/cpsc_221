//HeapPriorityQueue.hpp
#ifndef _HEAPPRIORITYQUEUE_HPP
#define _HEAPPRIORITYQUEUE_HPP

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

#include <vector>
#include "Compare.hpp"
#include "TodoList.hpp"

// An implementation of a priority queue, using
// a min-heap as the underlying data structure.
//
// the template type means that the priority queue
// will store elements of type T, and two elements
// of type T will be compared using operator() of
// a Compare class, which we will use as
//
// Compare() (elem1, elem2), where elem1 and elem2
// are of type T and Compare() ... returns an
// integer indicating how elem1 compares to elem2.
// > 0 is returned if elem1 is greater than elem2,
// < 0 is returned if elem1 is less than elem2, and
// 0 is returned if they are equal
//
// for instance, to check whether elem1 is less
// than or equal to elem 2 we will use
// 
// ( Compare() (elem1, elem2) ) > 0;
//
// See the VectorPriorityQueue class for examples of
// how to work with the templated stuff!

template <typename T, class Compare> class HeapPriorityQueue : 
  public TodoList<T>
  {
  public:
    HeapPriorityQueue();
    T remove();
    void add(T element);
    T get_next();
    int size();
    ~HeapPriorityQueue();
    
  private:
    // add any private member variables you need
    // and any additional helper functions.
    // 
    // We suggest a member variable that is a vector
    // of type T to hold the elements of the heap.
    vector <T> heap;
    
    // Heap-related helper functions.
    bool is_root(int index);
    int parent(int index);
    int first_child(int index);
    int num_children(int index);
    bool is_leaf(int index);
  };

#include "HeapPriorityQueue.cpp"

#endif
