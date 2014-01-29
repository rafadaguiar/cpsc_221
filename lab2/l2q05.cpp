#include <iostream>
using namespace std;


int main () {
  int x = 5, y = 15;
  int *p1, *p2;

  p1 = &x;      // x contains (5); y contains (15)
                // p1 contains (address of x); p2 contains (gargabe adress)
  cout << p1 <<endl;
  cout << p2 <<endl;
  
  p2 = &y;      // x contains (5); y contains (15)
                // p1 contains (address of x); p2 contains (address of y) 
  cout << p2 <<endl;

  *p1 = 6;      // x contains (6); y contains (15)
                // p1 contains (address of x); p2 contains (address of y)
  cout << *p1 <<endl;

  *p1 = *p2;    // x contains (15); y contains (15)
                // p1 contains (address of x); p2 contains (address of y)
  cout << *p2 <<endl;

  p2 = p1;      // x contains (15); y contains (15)
                // p1 contains (address of x); p2 contains (address of x)
  cout << p1 <<endl;

  *p1 = *p2+10; // x contains (25); y contains (15)
                // p1 contains (address of x); p2 contains (address of x)
  cout << *p1 <<endl;
  return 0;
}