//LinkedListStack.cpp
#ifndef _LINKEDLISTSTACK_CPP
#define _LINKEDLISTSTACK_CPP

// We suggest at least these includes:
#include "LinkedListStack.hpp"
#include <cstdlib> 
#include <cassert>
#include <iostream>


template <typename T>
LinkedListStack<T>::LinkedListStack()
{
  root = NULL;
}

template <typename T>
void LinkedListStack<T>::add(T elem)
{
  node * temp = new node();
  temp->val = elem;
  temp->next = root;
  root = temp; 
}

template <typename T>
T LinkedListStack<T>::remove()
{
  assert(root!=NULL);
  node * temp = new node();
  temp = root;
  root = root->next;
  temp = NULL;
  return root->val;

}

template <typename T>
T LinkedListStack<T>::get_next()
{
  assert(root!=NULL);
  return root->val;
}

template <typename T>
int LinkedListStack<T>::size()
{
  int count = 0;
  node *current = root;
  while(current){
    current = current->next;
    count++;
  }
  return count;
}

// template <typename T>
// void LinkedListStack<T>::ensure_capacity(int n)
// {
//   if (capacity < n) {
//     // Make plenty of room.
//     int target_capacity = (n > 2*capacity+1) ? n : (2*capacity+1);

//     // Set the current array aside and make room for the new one.
//     T * oldarray = array;
//     array = new T[target_capacity];

//     // Copy each element of the old array over.
//     for (int i = 0; i < top; i++) {
//       array[i] = oldarray[i];
//     }

//     capacity = target_capacity;

//     delete [] oldarray;
//   }
// }


template <typename T>
LinkedListStack<T>::~LinkedListStack()
{
  while(root){
    this->remove();    
  } 
}


#endif
