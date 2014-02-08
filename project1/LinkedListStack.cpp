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
  temp->next = NULL;
  return temp->val;
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

template <typename T>
LinkedListStack<T>::~LinkedListStack()
{
  while(root){
    this->remove();    
  } 
}


#endif
