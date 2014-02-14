//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>
#include <math.h>

                                                          /* HEAP starting at index 1 */

template <typename T, class Compare>
HeapPriorityQueue<T, Compare>::HeapPriorityQueue() {
  // empty
}

template <typename T, class Compare>
HeapPriorityQueue<T, Compare>::~HeapPriorityQueue() {
  // empty
}

template <typename T, class Compare>
void HeapPriorityQueue<T, Compare>::add(T elem) {
  int hole;
  heap.push_back(elem);
  if(size() < 1){           // Insert the first element twice, just to forget the index 0 and start from 1
    heap.push_back(elem);
  }
  hole = size();
  while(Compare() (heap[parent(hole)], elem) > 0 and hole > 1){
      heap[hole] = heap[parent(hole)];
      heap[parent(hole)] = elem;
      hole = parent(hole);  
    }
  heap[hole] = elem;  
}

template <typename T, class Compare>
T HeapPriorityQueue<T, Compare>::remove() {
  assert(size() > 0);
  int target,hole,left,right;
  T curr  = heap[1];
  heap.pop_back();
  hole = 1;

  while(first_child(hole) <= size()){
    left = first_child(hole);
    right = left+1;
    if(right <= size() and Compare() (heap[right],heap[left]) < 0){
      target = right;
    }else
    {
      target = left;
    }
    if(Compare()(heap[target],heap[size()+1]) < 0){
      heap[hole] = heap[target];
      hole = target;
    }
    else
      break;
  }
  heap[hole] = heap[size()+1];
  return curr;
}


template <typename T, class Compare>
T HeapPriorityQueue<T, Compare>::get_next() {
  if (heap.size() < 1) return (T)NULL;
  return heap[1];
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::size() {
  return int(heap.size()-1);
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::parent(int index) {
  // give back index's parent
  return int(floor(index/2));
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::first_child(int index) {
    // give back the the first (left) child of index
    return 2*index;
}

template <typename T, class Compare>
bool HeapPriorityQueue<T, Compare>::is_root(int index) {
  // true iff index is the root of the heap
  return (index == 1)?true:false;
}

template <typename T, class Compare>
bool HeapPriorityQueue<T, Compare>::is_leaf(int index) {
  // true iff index is a leaf (no children) in the heap
  // hint: easy to implement by using num_children!
  return (num_children(index) == 0)?true:false;
}

template <typename T, class Compare>
int HeapPriorityQueue<T, Compare>::num_children(int index) {
  // gives back the number of children index has (0, 1, or 2)
  int children = 0;
  if(size() < 2*index){
    children++;
  }
  if (size() < 2*index+1)
  {
    children++;
  }
  return children;
}

#endif
