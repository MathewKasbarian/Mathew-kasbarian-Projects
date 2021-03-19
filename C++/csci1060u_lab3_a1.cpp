#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

void sort (int numArray[]);
void swapper (int&a, int&b);


int main() {

    int nums[5];
    cout << "Please enter 5 integers" << endl;
    for(int x; x < 5; x++) {
        cin >> nums[x] ;
    }//end for

    sort(nums);
    
return 0;
    
}//end main

void sort (int numArray[]) {
    //sort
    for(int i = 0; i < 5; i++) {
        if (numArray[i] > numArray[i+1] ) {
        swapper (numArray[i], numArray[i+1] );
        i=-1;
        }//end if
        
    }//end for
    
    for (int j = 0; j < 5; j++) {
        cout << numArray[j] << " ";
    }
}




void swapper (int& a, int&b){
    int temp;
    temp =b;
    b = a;
    a = temp;
}

