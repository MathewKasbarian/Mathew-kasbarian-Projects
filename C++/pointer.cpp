#include <iostream>

using namespace std;

typedef int* intPtr;

int main() {
	
	int x = 5;
	intPtr p1 = &x;
	
	cout << "value x = " << x << endl;
	cout << "address x = " << &x << endl;
	cout << "what is the value of the pointer: " << *p1 << endl;
	//address of pointer
	cout << "address of *p = " << p1 << endl;
	//address of p
	cout << "address of p = " << &p1<< endl;
	
	
	


	return 0;
}