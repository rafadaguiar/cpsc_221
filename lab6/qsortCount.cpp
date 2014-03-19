#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;

int * x;
int comps = 0;

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

float c(int n){
	// Q4
	// C(n) = sum(from m=1 to n)[n-1+C(m-1)+C(n-m)]/n
	if(n<=1)return 0;
	float sum = 0.0;
	for(int m=1;m <=n; m++){
		sum += n-1 +c(m-1) + c(n-m);
	}
	return sum / n;
}
int qc(int n){
	// Q3
	int pivot;
	if(n <= 1) return 0;
	pivot = randint(0,n);
	return n-1 + qc(pivot) + qc(n-pivot-1); // recurrence relation for the quicksort average case
}

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quicksort(int a, int b) {
	// Q2
	int i, m;
	if (a >= b)
		return;

	swap(x[a], x[randint(a,b)]);
	m = a;
	for (i = a+1; i <= b; i++) {
		if (x[i] < x[a]){
			swap(x[++m], x[i]);
		}
		comps++;

	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 20

int main(int argc, char *argv[]) {
	srand(time(0));

	// Average number of comparisons = 5962
	int repetitions = 100, j;
	x = new int[NN];
	j = repetitions;
	while(j > 0){	
		for (int i=0; i<NN; ++i) {
			x[i] = rand() % NN;
		}
		quicksort(0, NN-1);
		j--;
	}
	// for (int i=0; i<NN; ++i) {
	// 	cout << x[i] << " ";
	// }
	// cout << endl;
	cout<<comps/repetitions<<endl;
	cout<<qc(NN)<<endl;
	// cout<<c(NN)<<endl;

	delete[] x;
	return 0;
}
