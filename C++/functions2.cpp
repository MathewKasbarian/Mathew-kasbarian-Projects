#include<iostream>

using namespace std;


int main() {
	
cout << "please enter 2 numbers: " << endl;

int num1, num2;

cin >> num1 >> num2

double result = average(num1, num2);

cout << result << endl;

	
return 0;
	
}

double average (int num1, int num2) {
	int sum = num1 + num2;
	
	double average = (double)sum/2;
	
	return average;
}