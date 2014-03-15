#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int * x;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	int i, m;
	if (a >= b) return;
	swap(x[a], x[randint(a,b)]);
	m = a;
	for (i = a+1; i <= b; i++) {
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		cout << x[i] << " ";
	}
	cout << endl;

	delete[] x;
	return 0;
}
