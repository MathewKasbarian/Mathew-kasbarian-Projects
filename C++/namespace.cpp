#include <iostream>

using namespace std;


namespace first_space{
	void func() {
		cout << "this is inside the first_space" << endl;
	}
}
	
namespace second_space{
	void func() {
		cout << " this is inside the second_space "<< endl;
	}
}

int main () {
	
	//call func from first name space
	first_space :: func();
	
	//calls func from second space 
	second_space :: func();
	
	{
		using namespace second_space;// this part is the same as the part above with :: just another way of doing it
		func();
	}
	
	return 0;
} 
	
