#include <iostream>
#include "binary_heap.cpp"

using namespace std;

/////////////////////////////////////////////////////////////////////
// MAIN

int input1[] = { 8, 3, 5, 6, 2, 9, 1, 7, 4, 0 };
int input2[] = { 4, 6, 1, 8, 2, 3 }; //,/21,11,23,45,0,4,8,9 };

int* copy(int* src, int size) {
	int *dest = new int[size];
	for (int i = 0; i < size; ++i) {
		dest[i] = src[i];
	}
	return dest;
}

int main() {
	int size1 = sizeof(input1) / sizeof(int);
	int *heap1 = copy(input1, size1);
	heapify(heap1, size1);
	cout << "heap1: ";
	printList(heap1, size1);
	printHeap(heap1, size1);

	int size2 = sizeof(input2) / sizeof(int);
	int *heap2 = copy(input2, size2);
	heapify(heap2, size2);
	cout << "heap2: ";
	printList(heap2, size2);
	printHeap(heap2, size2);

	int *heap = mergeHeap(heap1, heap2, size1, size2);
	int size = size1 + size2;
	if (heap != NULL) {
		cout << "merged: ";
		printList(heap, size);
		printHeap(heap, size);

		size = remove(heap, 2, size);
		cout << "remove(2): ";
		printList(heap, size);
		printHeap(heap, size);

		delete[] heap;
	}
	delete[] heap1;
	delete[] heap2;

	return 0;
}
