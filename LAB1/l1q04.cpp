#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>

using namespace std;

int main (){
  string s = "n";
  int number,ans;
  cout << "Game: Guess the correct number(int).\n";
  
  srand (time(NULL));
  ans = rand()%10;

  while(true){
  	cout << "Make a guess.\n";
  	cin >> number;
  	
  	if(number < 0){
      break;
    }else if(number == ans){
  		cout << "You Got it Right!\n";
  		break;
  	}else if(number > ans){
  		cout << "You should try a smaller number.\n";
  	}else if(number < ans){
  		cout << "You should try a greater number.\n";
  	}

  }
  cout << "End of the game.\n";
  return 0;
}