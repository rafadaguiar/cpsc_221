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
  num_elem = 0;
  capacity = INIT_SIZE;
  array =  new T[capacity];
}

template <typename T>
void ArrayQueue<T>::add(T elem)
{
  ensure_capacity(num_elem+1);
  array[back] = elem;
  back = (back+1) % capacity;
  num_elem++;
}

template <typename T>
T ArrayQueue<T>::remove()
{
  assert(num_elem > 0);
  T x;
  x = array[front];
  front = (front+1) % capacity;
  num_elem--; 
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
  // for (int i = 0; i < capacity; ++i)
  // {
  //   cout<<array[i]<<" ";
  // }
  // cout<<endl;
  return num_elem;
}

// implement ensure_capacity (but leave this for last/the final submission.. just start with lots of capacity!)
template <typename T>
void ArrayQueue<T>::ensure_capacity(int n)
{
  if (capacity<n){// if there's not already enough room
    // Make plenty of room.
    int target_capacity = 2*n;//(n<capacity)?2*capacity:2*n; // the larger of n and twice the current capacity

    // Set the current array aside and make room for the new one.
    T *new_array = new T[target_capacity];
    // Copy each element of the old array over.
    //
    // WARNING: you should copy all the elements of the queue in order
    // from front to back into the new array (doing the right thing if
    // the elements "wrap around" past the end of the array), but in
    // the new array, they should sit at indexes 0 to n-1 instead.

    int j = 0;
    
    for(;front < capacity;j++){
        new_array[j] = array[front];
        front++;
    } 
    if(back < front){ // if we wrap around
      for (int k = 0; k < back; ++k){
        new_array[j] = array[k];
        j++;
      }
    }
    
    // Fix front and back and capacity so they correspond to the new array.
    front = 0;
    back = n-1;
    capacity = target_capacity;
    // Delete the old array.
    T *temp = array;
    array = new_array;
    delete[] temp;
  }
}


template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
  delete[] array;
}

#endif
