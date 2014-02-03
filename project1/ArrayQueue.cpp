#ifndef _ARRAYQUEUE_CPP
#define _ARRAYQUEUE_CPP

//ArrayQueue.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of TodoList
template <typename T>
ArrayQueue<T>::ArrayQueue()
{ 
  front = 0;
  back = 0;
  capacity = 0;
  array =  new T[INIT_SIZE];
}

template <typename T>
void ArrayQueue<T>::add(T elem)
{
  array[back] = elem;
  back = (back+1) % INIT_SIZE;
  capacity++;
}

template <typename T>
T ArrayQueue<T>::remove()
{
  assert(capacity > 0);
  T x;
  x = array[front];
  front = (front+1) % INIT_SIZE;
  capacity--; 
  return x;
}

template <typename T>
T ArrayQueue<T>::get_next()// peak at the beginning of the queue
{
  return array[front];
}

template <typename T>
int ArrayQueue<T>::size()
{
  return capacity;
}

// TODO: implement ensure_capacity (but leave this for last/the final submission.. just start with lots of capacity!)
template <typename T>
void ArrayQueue<T>::ensure_capacity(int n)
{
  if (true /* TODO: if there's not already enough room */) {
    // Make plenty of room.
    int target_capacity = 0 /* TODO: the larger of n and twice the current capacity */;

    // TODO: Set the current array aside and make room for the new one.

    // TODO: Copy each element of the old array over.
    //
    // WARNING: you should copy all the elements of the queue in order
    // from front to back into the new array (doing the right thing if
    // the elements "wrap around" past the end of the array), but in
    // the new array, they should sit at indexes 0 to n-1 instead.

    // TODO: Fix front and back and capacity so they correspond to the new array.
    //
    // This part should be easy if you followed the warning above!

    // TODO: Delete the old array.
    // delete[] array;
  }
}


template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
  delete[] array;
}

#endif
