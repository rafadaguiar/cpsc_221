#ifndef _PUZZLESTATE_HPP
#define _PUZZLESTATE_HPP

#include <iostream>
#include <vector>
using namespace std;

/*
  PuzzleState.hpp
  Defines the abstract type PuzzleState

*/

class PuzzleState {
 public:
  // virtual destructor, since we have virtual methods
  virtual ~PuzzleState() { }

  // returns true if this PuzzleState is a solution for the puzzle
  virtual bool isSolution() = 0;

  // returns a vector of possible next positions for the puzzle.
  // These states are newly constructed; so, the caller should arrange
  // for their deletion.
  virtual vector<PuzzleState *> getSuccessors(void) = 0;

  // If you want to use BestFS, you must assign a priority value to
  // all puzzle states.  (If you don't want to use BestFS, you
  // can just return 0 for all PuzzleStates.)
  //
  // returns an integer representing a guess of how far we are
  // from a solution.  Bigger means farther from solution.
  virtual int getBadness(void) = 0;

  // print the puzzle state
  virtual void print (ostream& out) = 0;
};

#endif
