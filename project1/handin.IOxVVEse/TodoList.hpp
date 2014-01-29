#ifndef _TODOLIST_HPP
#define _TODOLIST_HPP

// generally not good to use a specific namespace in headers,
// for re-usability reasons, but we'll make an exception for
// this project
using namespace std;

// TodoList is a base interface representing a list of items
// that does not allow random-access semantics, but rather
// only addition and removal of elements, whose ordering
// in a concrete implementation will determine the ADT
// that is implemented (e.g. FIFO order -> queue)
template <typename T>
class TodoList {
 public:
  // a destructor declared as virtual in the
  // class declaration is given an implementation
  // so that the C++ "delete" operator on a subtype
  // will propagate up the type hierarchy into the
  // parent classes
  inline virtual ~TodoList() { }
  // return the next element, removing it from the list
  virtual T remove() = 0;
  // add an element to the todo list
  virtual void add(T element) = 0;
  // return the next element without removing it
  virtual T get_next() = 0;
  // returns whether or not there is at least 1 item in the list
  bool is_empty() { return size() == 0; }
  // returns the number of items in the list
  virtual int size() = 0;
};

#endif
