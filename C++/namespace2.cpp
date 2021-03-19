#include <iostream>

using namespace std;

int x = 50;

namespace outer {
	int x = 10;
	void func () {
		cout << "call from outer namespace" << endl;
	}
	
	namespace inner {
		int x = 20;
		void func() {
			cout << " call from innner namespace" << endl;
		}
	} 
} 

int main () {
	outer :: func();
	outer :: inner :: func();
	cout << x << endl;
	cout << outer  :: x << endl;
	cout << outer :: inner :: x << endl;
	
	
	
	return 0;
}