//Program 1 (file I/O): Copies the content of infile to outfile.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void){
  ifstream in("infile.txt"); // Open for reading
  ofstream out("outfile.txt"); // Open for writing
  string s;
  
  while(getline(in, s)){// Discards newline char
    out << s << "\n"; // ... add it to the new file
  }
  cout << "End of program\n";
  return 0;
}