#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>
using namespace std;

class Unit {
public:
	Unit();
	virtual ~Unit();

	void assertEquals(string msg, int expected, int actual);
	void assertVectorEquals(string msg, vector<int>& expected, vector<int>& actual);
	void assertNonNull(string msg, void* actual);
	void assertNull(string msg, void* actual);
	void printResults();

private:
	vector<string> failures;

	string toStr(vector<int>& v);
};

#endif /* UNIT_H_ */
