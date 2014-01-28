// drive.cpp: driver file for testing purposes
// we STRONGLY recommend using this to test your todolists for correctness!

#include <iostream>
#include "TodoList.hpp"
#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"
#include "Compare.hpp"


class CompareInt : Compare<int>{
 public:
  int operator() (int &left, int &right) {
    return left - right;
  }
  int operator() (int *left, int *right) {
    return operator() (*left, *right);
  }
};

int main(int argc, char * argv[]) {
  if (argc != 1) {
    cerr << "Usage: " << argv[0] << endl;
    cerr << "\t(accepts no parameters)" << endl;
  }

  //TodoList<int> * todolist = new ArrayStack<int>();  //  WORKING
  TodoList<int> * todolist = new ArrayQueue<int>();  // TEsting

  char command;
  int val;
  do {
    cerr << "Enter a one-letter command: " << endl;
    cerr << "- i: followed by a number, inserts that number" << endl;
    cerr << "- r: removes and prints the next item in the todolist" << endl;
    cerr << "- e: prints 'true' or 'false' depending on whether the todolist is empty" << endl;
    cerr << "- s: prints the size of the todolist" << endl;
    cerr << "- n: prints the next item in the todolist without removing it" << endl;
    cerr << "- q: quits" << endl;
    cerr << endl;

    cin >> command;
    switch (command) {
    case 'i': cin >> val; todolist->add(val); break;
    case 'r': val = todolist->remove(); cout << val << endl; break;
    case 'e': cout << (todolist->is_empty() ? "true" : "false") << endl; break;
    case 's': cout << todolist->size() << endl; break;
    case 'n': val = todolist->get_next(); cout << val << endl; break;
    case 'q': break;
    default: cerr << "Command '" << command << "' not understood; aborting." << endl;
      return 1;
    }
  } while (command != 'q');
}
