#include <iostream>
#include <cstdlib>
#include "binary_heap.cpp"

using namespace std;

/////////////////////////////////////////////////////////////////////
// MAIN

// These are leftover from the lab, to give you some small inputs for testing.
int input1[] = { 8, 3, 5, 6, 2, 9, 1, 7, 4, 0 };
int input2[] = { 4, 6, 1, 8, 2, 3 };

int* copy(int* src, int size) {
	int *dest = new int[size];
	for (int i = 0; i < size; ++i) {
		dest[i] = src[i];
	}
	return dest;
}


// const int REPS=1;	// Use this line when you're testing and debugging.
const int REPS=500000;	// Adjust this if needed to make timing easier.


int main(int argc, char *argv[]) {

	if( argc != 2 ) {
		cerr << "Usage: " << argv[0] << " n" << endl;
		return -1;
	}

	int size = atoi(argv[1]);

	int *heap1 = new int[size];

	for (int r=0; r<REPS; r++) {
		// UNCOMMENT ONE OF THE FOLLOWING TWO LINES
		// for (int i=0; i<size; i++) heap1[i] = size-i; // Worst Case (heapify)
		for (int i=0; i<size; i++) heap1[i] = i; // Best Case (heapify)

		// These are just to help you debug and play with the code.
		// cout << "Before: ";
		//printList(heap1, size);

		// UNCOMMENT ONE OF THE FOLLOWING TWO LINES
		heapify(heap1, size);
		// heapify2(heap1, size);

		// These are just to help you debug and play with the code.
		// cout << "After: ";
		//printList(heap1, size);
	}

	delete[] heap1;

	return 0;
}
