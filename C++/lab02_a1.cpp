#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


int main () {

	string intro = " Welcome to Guess That Number!";

	cout << "--------------------------------" << endl;
	cout << intro << endl;
	cout << "--------------------------------" << endl; 
	
	srand(time(NULL));

	int round = 1;
	int range = 5;
	int randNum = rand() % range; 
	
	int guess = 0;
	
	cout << "Round: " << round << endl;

	for ( int i =4; i >=0; i--) {
		cout  <<"Please guess a number less than " << range << ":"<< endl;
		
		cin >> guess;
		
		if (guess ==randNum) {
				cout << "you have guessed correctly" << endl;
				round ++;
				range = range *2;
				randNum = rand() % range;
				i = 5;
				cout << "Round: " << round << endl;
		}
		
		else {
			// guess is wrong 
			cout << "You have guess incorrectly try again. You have "  << i << " tries left"<< endl;
		}
		
		
		
	}//end for
		
	cout << "You have ran out of tries Game over!" << endl;
	cout << "the number was " << randNum << endl;









return 0;


}


