#ifndef _NULLDICT_HPP
#define _NULLDICT_HPP

#include "PredDict.hpp"

// generally not good to use a specific namespace in headers,
// for re-usability reasons, but we'll make an exception for
// this project
using namespace std;

// NullDict is a concrete class that implements the PredDict interface.

// NullDict ignores the add method, and find always returns false.
// Use this if you don't care about the dictionary (e.g., for a
// problem like Sudoku, where your successor generation guarantees
// that you'll never explore a duplicate state, and where you don't
// need the sequence of states leading to the solution).
// This will be much faster than any real dictionary implementation.

template <typename T>
class NullDict: public PredDict<T> {
 public:
  ~NullDict<T>() { }

  bool find(T key, T &pred) {pred=NULL; return false;}

  void add(T key, T pred) { }
};

#endif
