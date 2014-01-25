#ifndef _COMPARE_HPP
#define _COMPARE_HPP

// Compare is an abstract type implementing a single
// operation, the operator(), whose semantics are
// defined as:
//
// operator() (elem1, elem2) > 0 if
// elem1 is greater than elem2
//
// operator() (elem1, elem2) == 0 if
// elem1 is equal than elem2
// 
// operator() (elem1, elem2) < 0 if
// elem1 is lessthan elem2
//
// note that this differs from elem1 > elem2,
// elem1 == elem2, and elem1 < elem2, which
// may not have their operator>, operator==,
// operator< overloaded
//
// Two versions of the operator() are provided,
// one taking a pointer as an argument and one
// taking a reference. If a pointer is passed,
// then the comparison is done on the value
// to which the pointer points
//
// Subclasses implementing this interface are
// required to provide an implementation of the
// pointer version that is equivalent to
//     operator() (T *e1, T *e2) {
//       return operator() (*e1, *e2);
//     }
// or else the interface semantics are broken
template <typename T>
class Compare {
 public:
  virtual int operator() (T *left, T *right) = 0;
  virtual int operator() (T &left, T &right) = 0;
  virtual ~Compare() { }
};
#endif
