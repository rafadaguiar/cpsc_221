#include "unit.h"
#include <iostream>
#include <sstream>
using namespace std;

Unit::Unit() {
}

Unit::~Unit() {
}

void Unit::assertEquals(string msg, int expected, int actual) {
	if (expected != actual) {
		stringstream fmt;
		fmt << msg << ": Expected <" << expected << "> but was <" << actual << ">";
		failures.push_back(fmt.str());
	}
}

void Unit::assertVectorEquals(string msg, vector<int>& expected, vector<int>& actual) {
	bool fail = expected.size() != actual.size();
	for(unsigned int i=0; i < expected.size() && !fail; i++) {
		fail = expected[i] != actual[i];
	}
	if (fail) {
		stringstream fmt;
		fmt << msg << ": Expected\n<";
		fmt << toStr(expected);
		fmt << ">\nbut was\n<";
		fmt << toStr(actual);
		fmt << ">";
		failures.push_back(fmt.str());
	}
}

void Unit::assertNonNull(string msg, void* actual) {
	if (actual == NULL) {
		stringstream fmt;
		fmt << msg << ": Expected non-null value.";
		failures.push_back(fmt.str());
	}
}

void Unit::assertNull(string msg, void* actual) {
	if (actual != NULL) {
		stringstream fmt;
		fmt << msg << ": Expected null value.";
		failures.push_back(fmt.str());
	}
}

string Unit::toStr(vector<int>& v) {
	stringstream os;
	os << "[";
	for(unsigned int i=0; i < v.size(); i++) {
		os << v[i];
		if (i < v.size()-1) {
			os << ", ";
		}
	}
	os << "]";
	return os.str();
}

void Unit::printResults() {
	if (failures.empty()) {
		cout << "All tests passed.\n";
	} else {
		cerr << failures.size() << " failures:\n\n";
		for(unsigned int i=0; i < failures.size(); i++) {
			cerr << i+1 << ". " << failures[i] << "\n\n";
		}
	}
}
