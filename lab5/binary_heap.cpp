#include <iostream>
#include <iomanip>

using namespace std;

/**
 * PRE:  The capacity of the array pointed to by heap is at least size.
 * POST: The first size elements of heap are printed to the screen.
 */
void printList(int* heap, int size) {
	for (int i = 0; i < size; i++){
		cout << heap[i] << " ";
	}
	cout << endl;
}
/**
 *  PRE:  subtrees rooted at leftChild and rightChild of i are heaps.
 *  POST: subtree rooted at i is a heap.
 */
void swapDown(int* heap, int i, int size) {
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	int min = i;
	// find who holds smallest element of i and its two children
	if (leftChild < size && heap[leftChild] < heap[min])
		min = leftChild;
	if (rightChild < size && heap[rightChild] < heap[min])
		min = rightChild;
	// if a child holds smallest element, swap i's element to that child
	// and recurse.
	if (min != i) {
		swap(heap[i], heap[min]);
		swapDown(heap, min, size);
	}
}

/**
 * PRE:  The capacity of the array pointed to by heap is at least size.
 * POST: The first size elements of heap are a heap.
 */
void heapify(int* heap, int size) {
	for (int i = (size - 2) / 2; i >= 0; i--)
		swapDown(heap, i, size);
}

/**
 * PRE:  The capacity of the array pointed to by heap is at least size.
 * POST: The first size elements of heap are sorted in descending order.
 */
void sort(int* heap, int size) {
	heapify(heap, size);  // Heapify algorithm
	for (int i = size - 1; i > 0; i--) {
		swap(heap[0], heap[i]);
		swapDown(heap, 0, i);
	}
}

/**
 * PRE:  The capacity of the array pointed to by heap is at least size.
 *       node is the index of the root of the current sub-tree and
 *       it is at depth d in the whole heap
 * POST: The first size elements of heap are printed as a tree
 */
void printHeap(int *heap, int size, int node = 0, int d = 0) {
	if(node == 0)cout<<"Heap Tree:"<<endl;
	if(node >= size) return;
	printHeap(heap,size,2*node+2,d+1);
	cout << setw( 3 * d ) << ""; // output 3 * d spaces
	cout<<heap[node]<<endl;
	printHeap(heap,size,2*node+1,d+1);
}

/**
 * PRE:  heap points to an array representing a heap
 *       key is the value to be removed from the heap
 *       size is the number of elements in the heap
 * POST: all elements with key value = key have been removed from
 * 	the heap and size is the new heap size.
 */
int remove(int* &heap, int key, int & size) { // O(size)
	int count = 0; // number of duplicates to be removed
	for (int i = 0; i < size; ++i) // n
	{
		if(heap[i] == key)count++;
	}
	int *temp = new int[size-count];
	for (int i = 0, j = 0; i < size; ++i)// n
	{
		if(heap[i] != key){
			temp[j] = heap[i];
			j++; 
		}
		
	}
	heap = temp;
	return size-count;
}

/**
 * PRE:  heap1 and heap2 contain size1 and size2 elements respectively.
 * POST: output a new heap (whose size is size1+size2) containing all
 * 	the elements in heap1 and heap2 (including duplicates).
 */
int* mergeHeap(int* heap1, int* heap2, int size1, int size2) { // O(size1+size2)
	int *temp = new int[size1+size2];
	int i = 0, j = 0, k = 0;
	while(k < size2 and j < size1){
		if(heap1[j] < heap2[k]){
			temp[i] = heap1[j];
			j++;
		}else{
			temp[i] = heap2[k];
			k++;
		}
		i++;
	}
	if (i < size1+size2){
		while(j < size1){
			temp[i]=heap1[j];
			j++;
			i++;
		}
		while(k < size2){
			temp[i]=heap2[k];
			k++;
			i++;
		}
	}
 	return temp;
}
