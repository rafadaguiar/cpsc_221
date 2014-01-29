#ifndef _COMPAREPUZZLEBADNESS_HPP
#define _COMPAREPUZZLEBADNESS_HPP

#include "Compare.hpp"
#include "PuzzleState.hpp"
#include <cmath>
#include <cstring>

// ComparePuzzleBadness compares two PuzzleState
// according to their "badness" (see PuzzleState.hpp)
// 
// It is an implementation of the Compare abstract class,
// so it provides the operator() (see Compare.hpp)
//
class ComparePuzzleBadness : Compare<PuzzleState>{
 public:
  int operator() (PuzzleState &left, PuzzleState &right) {
    return left.getBadness() - right.getBadness();
  }
  // it would be nice to implement this in a superclass
  // but template classes and polymorphism in C++ don't
  // mix well and require type erasure
  int operator() (PuzzleState *left, PuzzleState *right) {
    return operator() (*left, *right);
  }
};

#endif
