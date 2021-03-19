
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    cout<<"============Welcome to the battleship lite========="<<endl;
    int round=1;
    int n=9;
    cout<<"Round "<<round<<" : "<<endl;

    while(true){
        srand(time(0));
        int target= (rand() % n) + 1;

        
        cout<<endl;
        int location ;
        cout<<"Guess the location of the battleship [ 0 , "<<n<<"]"<<endl;
        cin>>location;
        
        if(location==target){
            cout<<"HIT!"<<endl;
            cout<<"PLAY AGAIN! (Y/N) ";
            string y;
            cin>>y;
            if(y=="n"||y=="N"){
                break;
            }
            else{
                round++;
                cout << "Round: " << round << endl;
                
            }
        }
        srand(time(0));
        int cguess=(rand() % n) + 1;
        cout<<"Computer's Guess "<<cguess<<endl;
        if(cguess==target){
            cout<<"Computer Hit"<<endl;
            cout<<"PLAY AGAIN! (Y/N) ";
            string y;
            cin>>y;
            if(y=="n"||y=="N"){
                break;
            }
            else{
                round++;
                cout << "Round: " << round << endl;
                
            }
        
        
    }
}
}
