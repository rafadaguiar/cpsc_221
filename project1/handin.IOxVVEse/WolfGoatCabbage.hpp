#ifndef _WOLFGOATCABBAGE_HPP
#define _WOLFGOATCABBAGE_HPP

#include <iostream>
using namespace std;

/*
  WolfGoatCabbage.hpp

  Classic problem (from the middle ages) of crossing a river
  with a wolf, goat, and cabbage.
*/

class WolfGoatCabbage : public PuzzleState {
 public:
  WolfGoatCabbage();

  // Precondition: each input is 0 (before river) or 1 (after); inputs
  // are in order boat, wolf, goat, cabbage.
  WolfGoatCabbage(int, int, int, int);
  ~WolfGoatCabbage();

  // returns true if this PuzzleState is a solution for the puzzle
  bool isSolution();

  // returns a vector of possible next positions for the puzzle.
  // These states are newly constructed; so, the caller should arrange
  // for their deletion.
  vector<PuzzleState*> getSuccessors();

  // If you want to use BestFS, you must assign a priority value to
  // all puzzle states.  (If you don't want to use BestFS, you
  // can just return 0 for all PuzzleStates.)
  //
  // returns an integer representing a guess of how far we are
  // from a solution.  Bigger means farther from solution.
  int getBadness();

  // print the puzzle state
  void print (ostream& out);
 private:
  // This is a low-level, quick-and-dirty implementation.
  int boat; // position of human and boat: 0 means before; 1 means across
  int wolf; // position of wolf
  int goat; // position of goat
  int cabbage; // position of cabbage
};

#endif
