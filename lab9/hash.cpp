#include "hash.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

/*
	Questions:
	2)
		a) For LF < 0.18 the probRate of linear and quadratic probing were about the same.
			As this LF passed 0.18 the quadratic probing produced lower probRates
		b) The choice of the second hash function is also very important. I think that
			any h2 using prime numbers will produce better outputs than quadratic probing on the long run. 
		c) LF > 0.18
		d) For tables that are expected to fill up more than 1/5 I would use double hashing.
*/	

Hash::Hash(int _m) {
	//constructor
	m = _m;
	table = new int [m];
	clean();
}

Hash::~Hash() {
	//deconstructor
	delete[] table;
}

void Hash::tallyProbes(int p) {//Never needed this function...
	// Add the number of probes, p, for one insert operation to the tally.
	totalProbes += p;
	numInserts++;
}

void Hash::printStats() {
	cout << "Average probes/insert = " <<
			probeRate() << " = " <<
			totalProbes << "/" << numInserts << endl;
}

float Hash::probeRate() {
	return (float)totalProbes / (float)numInserts;
}

int Hash::hash(int k) {
	return k % m;
}

void Hash::qinsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with quadratic probing and hash(k) = k % m.

	// Tips:
	// - Look at the lecture slides if you don't remember how to implement these.
	// - You need to prevent against infinite loops. You should limit the number
	// of times you probe and print an error message upon exceeding this limit.
	// - You're welcome to add new declarations to hash.h, add to the constructor,
	// include libraries, or anything else you need. Just make it work.
	// - You're also welcome to modify the main() method to automate your testing.
	// In fact, you should!
	int i = 0, pre_inserts = numInserts;
	int h1 = hash(k);
	int probe;

	do{
		probe = (h1 + i*i) % m;
		if(table[probe] == EMPTY){
			table[probe] = k;
			numInserts++;
			break;
		}else{
			totalProbes++;
		}
		i++;	
	}while(table[probe] != EMPTY && i < m);
	if(pre_inserts == numInserts){
		cout<<"Fail on Insertion."<<endl;
	}
}

void Hash::linsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with linear probing and hash(k) = k % m.
	int i = 0, pre_inserts = numInserts;
	int h1 = hash(k);
	int probe;

	do{
		probe = (h1 + i) % m;
		if(table[probe] == EMPTY){
			table[probe] = k;
			numInserts++;
			break;
		}else{
			totalProbes++;
		}
		i++;	
	}while(table[probe] != EMPTY && i < m);
	if(pre_inserts == numInserts){
		cout<<"Fail on Insertion."<<endl;
	}
}

void Hash::dinsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with double hashing. Use the existing hash function
	// and also implement a second hash function.
	int h1 = hash(k);
	int h2 = 5 - (k % 5);
	int i = 0, pre_inserts = numInserts;
	int probe;
	
	do{
		probe = (h1 + h2*i) % m;
		if(table[probe] == EMPTY){
			table[probe] = k;
			numInserts++;
			break;
		}else{
			totalProbes++;
		}
		i++;	
	}while(table[probe] != EMPTY && i < m);
	if(pre_inserts == numInserts){
		cout<<"Fail on Insertion."<<endl;
	}

}

void Hash::print() {
	// Print the content of the hash table.

	for (int i=0; i<m; i++) {
		cout<<"["<<i<<"] ";
		if (table[i] != EMPTY)
			cout << table[i];
		cout << endl;
	}
}

void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

void Hash::clean(){
	for (int i=0; i<m; i++) {
		table[i] = EMPTY;
	}
	totalProbes = 0;
	numInserts = 0;
}

void Hash::ddel(int k){ // Using on the written assignment 3
	int h1 = hash(k);
	int h2 = 5 - (k % 5);
	int probe, i = 0;
	
	do{
		probe = (h1 + h2*i) % m;
		if(table[probe] == k){
			table[probe] = EMPTY;
			break;
		}
		i++;
	}while(table[probe] != k && i <= m);
}

// int main(int argc, char *argv[]) {
// 	int n, m;
// 	srand(time(0));

// 	if (argc != 4) {
// 		usage(argv);
// 	}
// 	n = atoi(argv[2]);
// 	m = atoi(argv[3]);
// 	Hash H(m);

// 	switch(argv[1][0]) {
// 	case 'l':
// 		for (int i=0; i<n; ++i) {
// 			H.linsert(rand() + 1);
// 		}
// 		   H.print();
// 		cout << "Linear: ";
// 		H.printStats();
// 		break;
// 	case 'q':
// 		for (int i=0; i<n; ++i) {
// 			H.qinsert(rand() + 1);
// 		}
// 		   H.print();
// 		cout << "Quadratic: ";
// 		H.printStats();
// 		break;
// 	case 'd':
// 		for (int i=0; i<n; ++i) {
// 			H.dinsert(rand() + 1);
// 		}
// 		   H.print();
// 		cout << "Double Hashing: ";
// 		H.printStats();
// 		break;
// 	default:
// 		usage(argv);
// 	}
// }
int main(){
	int m = 7919, n = 100; // 7919 is prime
	int j = 0, max_load_factor = m, step = n;
	int key;
	vector <int> keyv;
	float l[max_load_factor/step], q[max_load_factor/step], d[max_load_factor/step];
	Hash H(m);
	
	while(n <= max_load_factor){
		srand(time(0));
		keyv.clear();	
		for (int i = 0; i < n; ++i)
		{
			keyv.push_back(rand() + 1);
		}
		for (int i = 0; i<n; ++i) {
			H.linsert(keyv[i]);
		}
		l[j] = H.probeRate();
		H.clean();
		
		for (int i=0; i<n; ++i) {
			H.qinsert(keyv[i]);
		}
		q[j] = H.probeRate();
		H.clean();
		
		for (int i=0; i<n; ++i) {
			H.dinsert(keyv[i]);
		}
		d[j] = H.probeRate();
		H.clean();
		
		n +=step;
		j++;
	}
	cout<<"l,q,d"<<endl;
	for (int i = 0; i < max_load_factor/step; ++i)
	{
		cout<<l[i]<<","<<q[i]<<","<<d[i]<<endl;
	}	
}
// int main(int argc, char *argv[]) { // Using on the written assignment 3
// 	int m;
// 	int ins1 [] = {10,20,30,40,54,64,76,80,90};
// 	int del  [] = {64,54};
// 	int ins2 [] = {108};

// 	if (argc != 3) {
// 		usage(argv);
// 	}
	
// 	srand(time(0));
// 	m = atoi(argv[2]);
// 	Hash H(m);

// 	switch(argv[1][0]) {
// 	case 'd':
// 		for (int i=0; i<sizeof(ins1)/sizeof(int); ++i) {
// 			H.dinsert(ins1[i]);
// 		}
// 		for (int i=0; i<sizeof(del)/sizeof(int); ++i) {
// 			H.ddel(del[i]);
// 		}
// 		for (int i=0; i<sizeof(ins2)/sizeof(int); ++i) {
// 			H.dinsert(ins2[i]);
// 		}
// 		   H.print();
// 		cout << "Double Hashing: ";
// 		H.printStats();
// 		break;
// 	default:
// 		usage(argv);
// 	}
// }