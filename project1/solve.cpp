/*
  solve.cpp: contains 'main' function.

*/

#include <iostream>

#include <cstring>
#include <cstdlib>

// TODO: include any .hpp files of classes that you create and use here
// You may not need any!
#include "PuzzleState.hpp"
#include "WolfGoatCabbage.hpp"
#include "SliderPuzzle.hpp"
#include "Sudoku.hpp"

#include "LinkedListQueue.hpp"
#include "ArrayStack.hpp"
#include "VectorPriorityQueue.hpp"
// TODO:  implement these classes
#include "LinkedListStack.hpp" // DONE
#include "ArrayQueue.hpp" // DONE
//#include "HeapPriorityQueue.hpp"
#include "ComparePuzzleBadness.hpp"

#include "NullDict.hpp"
#include "LinkedListDict.hpp"
// TODO:  finish this class
// #include "BSTDict.hpp"
#include "ComparePuzzleState.hpp"

using namespace std;


// This function does the actual solving.
void solvePuzzle(PuzzleState *start, TodoList<PuzzleState*> &active, PredDict<PuzzleState*> &seen, vector<PuzzleState*> &solution) {

  PuzzleState *state;
  PuzzleState *temp;

  active.add(start); // Must explore the successors of the start state.
  seen.add(start,NULL); // We've seen this state.  It has no predecessor.

  while (!active.is_empty()) {
    // Loop Invariants:
    // 'seen' contains the set of puzzle states that we know how to reach.
    // 'active' contains the set of puzzle states that we know how to reach,
    //    and whose successors we might not have explored yet.

    state = active.remove();
    // Note:  Do not delete this, as this PuzzleState is also in 'seen'

    // TODO: uncomment the next two lines for debugging, if you'd like!
    //cout << "Exploring State: \n";
    //state->print(cout);

    if (state->isSolution()) {
      // Found a solution!
      cout << "Found solution! \n";
      state->print(cout);

      // Follow predecessors to construct path to solution.
      temp = state;
      while (temp!=NULL) {
	solution.push_back(temp);
	// Guaranteed to succeed, because these states must have been
	// added to dictionary already.
        seen.find(temp,temp);
      }
      return;
    }

    vector<PuzzleState*> nextMoves = state->getSuccessors();
    for (unsigned int i=0; i < nextMoves.size(); i++) {
      if (!seen.find(nextMoves[i], temp)) {
        // Never seen this state before.  Add it to 'seen' and 'active'
        active.add(nextMoves[i]);
        seen.add(nextMoves[i], state);
      }
      else {
	// We're not using this duplicate state; 
	// so, we should delete it.
	delete nextMoves[i];
      }
    }
  }

  // Ran out of states to explore.  No solution!
  cout << "No solution!" << endl;
  solution.clear();
  return;
}

int main (int argc, char *argv[])
{
  // No command line arguments currently.
  //
  // (Mostly here to avoid the aggressive "unused parameter" compiler
  // warning!)
  if (argc > 1) {
    cerr << "Usage: " << argv[0] << endl;
    cerr << "\t(no command line arguments currently accepted)" << endl;
    exit(1);
  }

  PuzzleState *startState;

  // TODO: Initialize startState with an object of the type of puzzle you want solved.
  // For some kinds of puzzles, you will want to pass in a parameter
  // to specify the starting position (e.g., for the 8- or 15-puzzles.)

  startState = new WolfGoatCabbage();

  // startState = new Sudoku("000000000000000000000000000000000000000000000000000000000000000000000000000000000");

  // Note: 1/2 of all positions are not possible.  If a run takes a huge
  // amount of time, try exchanging two adjacent numbers and trying again.
  // startState = new SliderPuzzle(3,3,"8 7 6 5 4 3 2 1 0");
  // startState = new SliderPuzzle(3,4,"11 10 9 8 7 6 5 4 3 1 2 0");
  // startState = new SliderPuzzle(4,4,"15 14 13 12 11 10 9 8 7 6 5 4 3 1 2 0");


  // TODO:  Uncomment one of these, to select BFS, DFS, or BestFS
  // Later, you will put declarations here to use your new implementations
  // (ArrayQueue, LinkedListStack, and HeapPriorityQueue).
  // LinkedListQueue<PuzzleState*> activeStates;
  ArrayQueue<PuzzleState*> activeStates; //  (DONE)
  // LinkedListStack<PuzzleState*> activeStates; //  (DONE)
  //ArrayStack<PuzzleState*> activeStates; //  (WORKING)
  // VectorPriorityQueue<PuzzleState*, ComparePuzzleBadness> activeStates;

  // TODO:  Uncomment one of these to pick the dictionary implementation
  // NullDict<PuzzleState*> seenStates;
  LinkedListDict<PuzzleState*, ComparePuzzleState> seenStates;
  // BSTDict<PuzzleState*, ComparePuzzleState> seenStates;

  vector<PuzzleState*> solution;

  solvePuzzle(startState, activeStates, seenStates, solution);

  // Print out solution
  //
  // Note: casting to avoid the type conversion warning.  It would be
  // better to use a long unsigned int, since that's the return type
  // of solution.size(), but for code simplicity, we are introducing a
  // potential error and using an int for immense solutions (billions
  // of steps).
  for (int i=(int)solution.size()-1; i >= 0; i--) {
    cout << "STEP " << solution.size()-i << ":\n";
    solution[i]->print(cout);
    cout << endl;
  }
  
  delete startState;

  return 0;
}
