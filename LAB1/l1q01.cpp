#include <iostream>
#include <vector>

using namespace std;

int fill_array (vector <int> a, int plus){
	int i = a[0];
	int count = 0;
	
	cout << i << ">";
	
	while(count < a.size()-1){
		a[i] = i;
		i+=plus;
		count++;
		cout << i << ">";
	}
	cout << "\n";
}

int main(){
	vector <int> a(10);
	int plus;
	cout << "Insert the first number of the vector(int).\n";
	cin >> a[0];
	cout << "Insert the plus factor(int).\n";
	cin >> plus;
	cout << "###\n";
	fill_array(a,plus);
	return 0;
}