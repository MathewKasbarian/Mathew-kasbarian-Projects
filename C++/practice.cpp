#include <iostream>

using namespace std;

int power (int a, int exponent) {
	int result = 1;
	for(int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}

int main() {
	
	int base= 2;
	int exponent = 3;
	
	cout << power (base, exponent) << endl;
	
	
	return 0;
	
}

