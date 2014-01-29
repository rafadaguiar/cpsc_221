//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
template <typename T>
LinkedListQueue<T>::LinkedListQueue()
{
  head = NULL;
  tail = NULL;
  _size = 0;
}

template <typename T>
void LinkedListQueue<T>::add(T elem)
{
  if(head == NULL)
    {
      head = new node;
      head->next = NULL;
      head->data = elem;
      tail = head;
      _size++;
    }
  else
    {
      tail->next = new node;
      tail->next->data = elem;
      tail->next->next = NULL;
      tail = tail->next;
      _size++;
    }
}

template <typename T>
T LinkedListQueue<T>::remove()
{
  assert(!this->is_empty());
  T ret = head->data;
  node* temp = head->next;
  delete head;
  head = temp;
  _size--;
  return ret;
}

template <typename T>
T LinkedListQueue<T>::get_next()
{
  assert(!this->is_empty());
  return head->data;
}

template <typename T>
int LinkedListQueue<T>::size()
{
  return _size;
}

template <typename T>
LinkedListQueue<T>::~LinkedListQueue()
{
  while(!this->is_empty())
    this->remove();
}

#endif

