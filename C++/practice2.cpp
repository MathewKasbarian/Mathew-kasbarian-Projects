#include <iostream>

using namespace std;

int main() {
	int size = 6;
	int array[size] = {5, 3 , 8, 9 ,1 , 87};
	
	
	int first;
	int second;
	
	if (array[0] <= array[1] ) {
		first = array[0];
		second = array[1];
	}
	
	else {  
		first = array[1];
		second = array[0];
	}
	
	for (int i = 2; i < size; i++) {
		
		if (array[i] <= first) {
			second = first;
			first = array[i];
		}
		
		else if (array[i] < second) {
			second = array[i];
		}
	}
	
	cout << first << " " << second << endl;
	
	return 0;
}