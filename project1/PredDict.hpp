#ifndef _PREDDICT_HPP
#define _PREDDICT_HPP

// generally not good to use a specific namespace in headers,
// for re-usability reasons, but we'll make an exception for
// this project
using namespace std;

// PredDict is a base interface representing a dictionary that
// keeps track of the predecessor state of each state in the
// dictionary (i.e., a state which leads to the given state).

// We will use this both to keep track of whether we've
// explored a state before (so we don't duplicate work
// or get stuck in cycles), as well as to generate the
// sequence of states leading to a puzzle solution, if
// that's desired.

// Different implementations will hvae different efficiency.

template <typename T>
class PredDict {
 public:
  // a destructor declared as virtual in the
  // class declaration is given an implementation
  // so that the C++ "delete" operator on a subtype
  // will propagate up the type hierarchy into the
  // parent classes
  virtual ~PredDict() { }

  // Returns true iff the key is found.
  //
  // If the key is found, pred is set to the predecessor.
  // Note that if T is a pointer type, you should NOT
  // delete the object pointed to by pred, as there will
  // still be a pointer to that object inside the dictionary.
  virtual bool find(T key, T &pred) = 0;

  // add a (key, predecessor) pair to the dictionary
  //
  // Note:  If T is a pointer type, the caller should NOT
  //        delete the object pointed to by key or pred,
  //        since the dictionary will keep a link to the object.
  virtual void add(T key, T pred) = 0;
};

#endif
