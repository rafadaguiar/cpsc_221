#include <iostream>
#include "binary_heap.cpp"

using namespace std;

/**
 *  PRE:  heap is a valid heap, except for possibly element i.
 *  POST: heap is a valid heap, except for possibly the parent of i.
 */
void swapUp(int* heap, int i, int size) {
	/**
	 * THIS FUNCTION NEEDS TO BE IMPLEMENTED
	 */
}

/**
 * PRE:  heap is a valid heap of size size.
 * POST: heap is a valid heap of size (size+1) now containing toAdd.
 */
void insert(int toAdd, int* heap, int& size) {
	/**
	 * THIS FUNCTION NEEDS TO BE IMPLEMENTED
	 */
}

/////////////////////////////////////////////////////////////////////
// MAIN

int heap[16];
int input1[] = { 8, 3, 5, 6, 2, 9, 1, 7, 4, 0 };
int input2[] = { 4, 6, 1, 8, 2, 3};

int main() {
	int sz = 0;
	for (int i = 0; i < 10; i++) {
		insert(input1[i], heap, sz);
		if (i == 0 || i == 1 || i == 2 || i == 9) {
			cout << "heap after inserting " << input1[i] << " (after " << i+1 << " insertions):" << endl;
			printHeap(heap, sz);
		}
	}
	for (int i = 0; i < 6; i++) {
		insert(input2[i], heap, sz);
	}
	cout << "Final heap: " << endl;
	printHeap(heap, sz);
}
