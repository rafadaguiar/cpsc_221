#include <iostream>
#include <cstdlib>
#include "insertion.h"

using namespace std;
// insertion sort with several errors

void getArgs( int ac, char **av ) {
  int i;
  numInputs = ac - 1;
  for( i = 0; i < numInputs; i++ )
    x[i] = atoi( av[ i+1 ] );
}

void scootOver( int jj ) {// shift the array elements to right
  int k;                 
  for( k = numInputs-1; k > jj; k-- )
    y[k] = y[ k-1 ];
}

int greaternum(){
  int i,num=0;
  for(i = 0; i < numInputs;i++){
    if(x[i] > num){
      num = x[i];
    }
  } 
  return num;
} // fix cases not stating with the greater number

void insert( int newY ) {
  int j;
  
  if( numY == 0 ) {
    y[0] = greaternum();
    //numY++;
  }
  // Need to insert just before the first y element that newY is less than
  for( j=0; j< numY+1; j++ ) {
    if( newY < y[j] ) {
      // shift y[j], y[j+1], ... rightward before inserting newY
      scootOver( j );
      y[j] = newY;
      return;
    }
  }
}

void processData() { //catches the input and passes it to inser one by one
  for( numY = 0; numY < numInputs; numY++ ){
    // insert new y in the proper place among y[0],....,y[numY-1]
    insert( x[ numY ] );
  } 
}

void printResults() {
  int i;
  for( i=0; i<numInputs; i++ )
    cout << y[i] << " ";
  cout << endl;
}

int main( int argc, char ** argv ) {// the program prints the input in the reverse order
  getArgs( argc, argv );
  processData();
  printResults();
}
