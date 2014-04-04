#ifndef HASH_H
#define HASH_H

#define EMPTY -1	// indicates an empty slot (so don't hash -1)

class Hash {
public:
	Hash(int _m);
	~Hash();
	int hash(int key);
	void qinsert(int key);
	void linsert(int key);
	void dinsert(int key);
	void print();
	void printStats();
	float probeRate();
	void clean();
	void ddel(int key);

private:
	int* table;
	int m;
	int totalProbes;
	int numInserts;
	void tallyProbes(int p);
};

#endif
