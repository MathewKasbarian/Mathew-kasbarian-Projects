#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	string filename;
	int size = 5;
	string data [5];
	
	
	cout << "please enter the file name"<< endl;
	cin << filename;
	
	ofstream myOutput (filename);
	
	cout << "enter" <<size   << " items: " << endl;
	
	for (int i=0; i< size; i++) {
		cin >> data[i];
	}
	cout << "dislpay array items" << endl;
	for( int i =0; i <size; i++) {
		myOutput << data[i] << endl;
	}
	
	myOutput.close();
	
	//reading from file 
	
	cout << "readinfg from file with name" << filename << endl;
	ifstream myInput (filename);
	
	// Read from the filename 
	while (!myInput.eof()) { //eof stand for end of 
		string line;
		myInput >> line;
		cout << line << endl;
	}
	
	myInput.close();


return 0;	
}