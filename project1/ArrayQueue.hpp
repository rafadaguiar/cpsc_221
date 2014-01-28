//ArrayQueue.hpp
#ifndef _ARRAYQUEUE_HPP
#define _ARRAYQUEUE_HPP

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

#include "TodoList.hpp"

// This skeleton file (along with the .cpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of TodoList
template <typename T>
class ArrayQueue: public TodoList<T>
{
 public:
  ArrayQueue(); // constructor
	
  
  // TodoList interface
  void add(T elem);
  T remove();
  T get_next();
  int size();
  void show();
  ~ArrayQueue(); // destructor

	// Note: For your milestone submission, you may feel free to change 
	// INIT_SIZE to a large enough number such that you can avoid resizing 
	// the array in ensure_capacity. For your final submission, set INIT_SIZE 
	// to a small enough number such that the the array does resize at some point.
  static const int INIT_SIZE = 6;

 private:
  // A helper function that consumes a number and ensures the queue
  // has enough space for that many elements.  (In C++, it might be
  // better style--and functionality--to make the argument (and all 
  // of our parameters) unsigned ints rather than ints.. but things
  // are complex enough for this assignment!
  void ensure_capacity(int n);

  // a pointer to the underlying array with elements of type T
  // use an explicit pointer, NOT T array[..] so you can resize.
  // Reminder: remember to to implement the queue as a circular array.
  // Points will be deducted if the array is not circular
  T * array;
  T myarray [INIT_SIZE];
  // TODO: list additional private member variables here
  int front, back;
};

#include "ArrayQueue.cpp"

#endif
