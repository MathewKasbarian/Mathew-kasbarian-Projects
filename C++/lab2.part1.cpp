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
    
    srand(time(0));

    int round = 1;
    int range = 9;
    int randNum = rand() % range;
    
    int guess = 0;
    
    cout << "Round: " << round << endl;

    for ( int i =0; i <=5; i++) {
        
        cout  <<"Guess a location of the battleship " << range << ":"<< endl;
        
        cin >> guess;
        
        if (guess ==randNum) {
                cout << "HIT!" << endl;
                range = range +10;
                randNum = rand() % range;
                i = 0;
            cout << "PLAY AGAIN! (Y/N): " << endl;
            string y;
            cin >> y;
            if(y=="n"||y=="N"){
                break;
            }
            else{
                round++;
                cout << "Round: " << round << endl;
                
            }
        }
        
        else {
            int tries=5-i;
            cout << "MISS! "  << tries << " tries left"<< endl;
            if(i==5){
                cout << "You have ran out of tries the battleship was in position " << randNum << endl;
                break;
            }
        }
        
        
        
    }
        
    cout << "Game over!" << endl;









return 0;


}


