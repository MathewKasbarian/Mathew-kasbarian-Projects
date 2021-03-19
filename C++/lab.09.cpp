#include <iostream>

using namespace std;

int main() {
	
	int SIZE;
	cout <<" please enter a size for the array" << endl;
	cin >> SIZE;
	int *array; 
	array = new int [SIZE-1];
	
	for (int i = 0; i < SIZE; i++) {
		cout << "please enter the digit" << endl;
		cin >> array[i];
	}
	
	for (int j = 0; j <SIZE; j++) {
		int count = 0;
		for (int n = 0; n < SIZE; n++) {
			if (j > n && array[j] == array[n]) {
				break;
			}
			if (array[j] == array[n]) {
				count ++;
			}
		}
		if (count != 0) {
			cout << "# of "<< array[j] << " in the list " << count << endl;
		}
	}		
	
	return 0;
}