#include "hash.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/*
	Questions:
	2)
		a) For LF < 0.12 the probRate of linear and quadratic probing were about the same.
			As this LF passed 0.12 the quadratic probing produced lower probRates
		b) The choice of the second hash function is also very important. I think that
			any h2 using prime numbers will produce better outputs than quadratic probing on the long run. 
		c) LF > 0.21
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
	int probe = k, LIMIT = m/2;

	do{
		probe = (hash(k) + i*i) % m;
		if(table[probe] == EMPTY){
			table[probe] = k;
			numInserts++;
			break;
		}else{
			totalProbes++;
			// cout<<"Probing k="<<k<<" , i="<<i<<" , probe="<<probe<<endl;
		}
		i++;	
	}while(table[probe] != EMPTY && i != m && i < LIMIT);
	if(pre_inserts == numInserts){
		// cout<<"Fail on Insertion(Maximum number of probes["<<LIMIT<<"] exceeded)."<<endl;
	}
}

void Hash::linsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with linear probing and hash(k) = k % m.
	int i = 0, pre_inserts = numInserts;
	int probe = k;

	do{
		probe = (hash(k) + i) % m;
		if(table[probe] == EMPTY){
			table[probe] = k;
			numInserts++;
			break;
		}else{
			totalProbes++;
			// cout<<"Probing "<<k<<" "<<probe<<endl;
		}
		i++;	
	}while(table[probe] != EMPTY && i != m);
	if(pre_inserts == numInserts){
		// cout<<"Fail on Insertion."<<endl;
	}
	
}

void Hash::dinsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with double hashing. Use the existing hash function
	// and also implement a second hash function.
	int h1 = hash(k);
	int h2 = 5 - (k % 5);
	int probe = (h2 + h1) % m;

	if(table[h1] == EMPTY){
		table[h1] = k;
		numInserts++;
	}else if(table[h2] == EMPTY){
		table[probe] = k;
		numInserts++;
		totalProbes++;	
	}else{
		// cout<<"Fail on Insertion."<<endl;
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
// 		   // H.print();
// 		cout << "Linear: ";
// 		H.printStats();
// 		break;
// 	case 'q':
// 		for (int i=0; i<n; ++i) {
// 			H.qinsert(rand() + 1);
// 		}
// 		   H.print();
// 		cout << "Quadratic: ";
// 		// H.printStats();
// 		break;
// 	case 'd':
// 		for (int i=0; i<n; ++i) {
// 			H.dinsert(rand() + 1);
// 		}
// 		   // H.print();
// 		cout << "Double Hashing: ";
// 		H.printStats();
// 		break;
// 	default:
// 		usage(argv);
// 	}
// }
int main(){
	int m = 7919, n = 100; // 7919 is prime
	int j = 0, max_load_factor = m/2, step = n;

	float l[max_load_factor/step], q[max_load_factor/step], d[max_load_factor/step];
	Hash H(m);
	
	while(n <= max_load_factor){
		srand(time(0));

		for (int i = 0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		l[j] = H.probeRate();
		H.clean();
		
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		q[j] = H.probeRate();
		H.clean();
		
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
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