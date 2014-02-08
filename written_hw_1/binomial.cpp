#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

unsigned long binom_coef1(unsigned long n, unsigned long k);
unsigned long binom_coef2(unsigned long n, unsigned long k);

// UNCOMMENT ONE OF THE FOLLOWING TWO LINES AS DIRECTED IN THE ASSIGNMENT.
//const int REPEAT_COUNT = 1;  // Use this with binom_coef1
const int REPEAT_COUNT = 1000000;  // Use this with binom_coef2

int main(int argc, char *argv[]) {
  // Tester program for the binomial coefficient algorithms

  if( argc != 3 ) {
    cerr << "Usage: " << argv[0] << " n k" << endl;
    return -1;
  }

  unsigned long n = atol(argv[1]);
  unsigned long k = atol(argv[2]);

  cout << "On this machine, unsigned long is " << sizeof(unsigned long) << " bytes." << endl;

  unsigned long result;
  for (int repeat=0; repeat < REPEAT_COUNT; repeat++) {

    // UNCOMMENT ONE OF THE FOLLOWING CALLS TO PICK WHICH ALGORITHM TO USE
    //result = binom_coef1(n,k);
    result = binom_coef2(n,k);

  }

  cout << "The value of " << n << " choose " << k << " is " << result << endl;

  return 0;
}


// Compute n choose k
// -- First Algorithm
unsigned long binom_coef1(unsigned long n, unsigned long k) {
  if (k==0) return 1;
  if (k==n) return 1;
  if (k>n) return 0;

  return binom_coef1(n-1,k) + binom_coef1(n-1,k-1);
}


// Compute n choose k
// -- Second Algorithm
unsigned long binom_coef2(unsigned long n, unsigned long k) {
  unsigned long *table = new unsigned long[(n+1)*(k+1)];

  for (int i=0; i<=n; i++) {
    for (int j=0; j<=k; j++) {
      table[i*k+j] = 0;
    }
  }

  table[0] = 1;

  for (int i=1; i<=n; i++) {
    for (int j=0; j<=k; j++) {
      if (j==0) table[i*(k+1)+j] = 1;
      else table[i*(k+1)+j] = table[(i-1)*(k+1)+j] + table[(i-1)*(k+1)+j-1];
    }
  }

  unsigned long result = table[n*(k+1)+k];
  delete [] table;
  
  return result;
}
