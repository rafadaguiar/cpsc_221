#ifndef _COMPAREPUZZLESTATE_HPP
#define _COMPAREPUZZLESTATE_HPP

#include "Compare.hpp"
#include "PuzzleState.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// ComparePuzzleState compares two PuzzleStates.
// The goal is to make a total order over the PuzzleStates,
// so that we can uniquely identify a PuzzleState (to tell
// whether we've explored it before) and also order them,
// so we can use more efficient dictionary ADT implementations
// 
// It is an implementation of the Compare abstract class,
// so it provides the operator() (see Compare.hpp)

class ComparePuzzleState : Compare<PuzzleState>{
 public:
  int operator() (PuzzleState &left, PuzzleState &right) {
    // This is an inefficient implementation, but it has
    // the desired functionality, doesn't require breaking the API
    // of the PuzzleState class, and is easy to code.
    ostringstream left_stream;
    ostringstream right_stream;

    left.print(left_stream);
    right.print(right_stream);
    return left_stream.str().compare(right_stream.str());
  }
  // it would be nice to implement this in a superclass
  // but template classes and polymorphism in C++ don't
  // mix well and require type erasure
  int operator() (PuzzleState *left, PuzzleState *right) {
    return operator() (*left, *right);
  }
};

#endif
