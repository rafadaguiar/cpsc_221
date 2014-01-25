#ifndef _ARRAYSTACK_CPP
#define _ARRAYSTACK_CPP

//ArrayStack.cpp

#include "ArrayStack.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
ArrayStack<T>::ArrayStack() : top(0)
{
  array = new T[INIT_SIZE];
  capacity = INIT_SIZE;
}

template <typename T>
void ArrayStack<T>::add(T elem)
{
  ensure_capacity(size()+1);
  array[top] = elem;
  top++;
}

template <typename T>
T ArrayStack<T>::remove()
{
  assert(!this->is_empty());
  top--;
  return array[top];
}

template <typename T>
T ArrayStack<T>::get_next()
{
  assert(!this->is_empty());
  return array[top-1];
}

template <typename T>
int ArrayStack<T>::size()
{
  return top;
}

template <typename T>
void ArrayStack<T>::ensure_capacity(int n)
{
  if (capacity < n) {
    // Make plenty of room.
    int target_capacity = (n > 2*capacity+1) ? n : (2*capacity+1);

    // Set the current array aside and make room for the new one.
    T * oldarray = array;
    array = new T[target_capacity];

    // Copy each element of the old array over.
    for (int i = 0; i < top; i++) {
      array[i] = oldarray[i];
    }

    capacity = target_capacity;

    delete [] oldarray;
  }
}


template <typename T>
ArrayStack<T>::~ArrayStack()
{
  delete [] array;
}

#endif
