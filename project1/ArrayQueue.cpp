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
  //array = &myarray;
  front = 0;
  back = 0;
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // TODO: implement constructor
}

template <typename T>
void ArrayQueue<T>::add(T elem)
{
  this->myarray[back] = elem;
  this->back = (back+1) % this->size();
}

template <typename T>
T ArrayQueue<T>::remove()
{
  T x;
  x = this->myarray[front];
  this->front = (front+1) % this->size(); 
  return x;
}

template <typename T>
T ArrayQueue<T>::get_next()// peak at the beginning of the queue
{
  return this->myarray[front];
}

template <typename T>
int ArrayQueue<T>::size()
{
  return sizeof(this->myarray)/sizeof(this->myarray[0]);
}

template <typename T>
void ArrayQueue<T>::show(){
  for (int i = 0; i < this->size(); ++i)
  {
    cout << this->myarray[i];
  }
  cout <<endl;
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
  }
}


template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
  // TODO: implement the destructor

  // do any cleanup like deallocating
  // any dynamically allocated memory
}

#endif