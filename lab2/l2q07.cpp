#include <iostream>
using namespace std;

int a = 7, l = 10;
int *b = &a, *s;
int **c = &b; // c is a pointer to a pointer
 

void test( int &x, int* &y, int** &z ) { // using the & means that we're passing the actual variable(arg by reference) 
    x++;                              // to the function any changes within the function will change the value outside
    //y++;
    z = &s;
    s = &l;
}

int main(){ 
  test(a,b,c);
  cout << a << " " << *b << " " << *(*c)<< endl; // *c = address of s and s = address of l; therefore, *(*c) is the value of l
  return 0;
}