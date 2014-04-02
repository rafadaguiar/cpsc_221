#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>	// std::stack

using namespace std;

// An object to keep track of intervals in an array.
struct Interval {
	int lo;
	int hi;
};

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

// Allegedly, an iterative version of the quicksort function above
void iter_quicksort(int a, int b) {
	stack<Interval> todo;
	Interval temp;

	temp.lo = a;
	temp.hi = b;
	todo.push(temp);
	while (!todo.empty()) {
		int i, m;
		// C++ STL Stack class implements pop() weirdly.
		a = todo.top().lo;
		b = todo.top().hi;
		todo.pop(); // C++ STL pop() doesn't return the valueu popped.

		if (a >= b) continue; // Goes to bottom of loop

		// This is the partitioning step.
		// It's identical to the code in the recursive version
		// and works the same way.
		swap(x[a], x[randint(a,b)]);
		m = a;
		for (i = a+1; i <= b; i++) {
			if (x[i] < x[a])
				swap(x[++m], x[i]);
		}
		swap(x[a],x[m]);

		// quicksort(a, m-1);
		temp.lo = a;
		temp.hi = m-1;
		todo.push(temp);
		//quicksort(m+1, b);
		temp.lo = m+1;
		temp.hi = b;
		todo.push(temp);
	}
}



#define NN 20

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	iter_quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		cout << x[i] << " ";
	}
	cout << endl;

	delete[] x;
	return 0;
}
