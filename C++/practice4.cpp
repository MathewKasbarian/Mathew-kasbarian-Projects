#include <iostream>
#include <sstream>

using namespace std;

int convertStringToInt(string str) {
	int num  = 0;
	
	int n = str.length();
	int i = 0;
	
		int signOfNum = 1;
	
	if (str.at(i) == '-') {
		signOfNum = -1;
		
		i++;
	}

	while (i<n) {
		num *=10;
		num = num  + str.at(i) - '0';
		
		i++;
	}
	
	num *= signOfNum;
	
	return num;
}

string reverseString (string str) {
	int n = str.length();
	
	for (int i = 0; i<n/2; i++) {
		swap(str[i] , str[n-i-1]);
		
	}
	return str;
}

string intToString (int num) {
	
	string str;
	bool sign = false;
	if (num < 0) { 
		sign = true;
		num *= -1;
	}
	
	while (num != 0) { 
		int n = num % 10;
		n = n+ '0';
		char c = (char) n;
		
		str += c;
		num/=10;
	}
	
	if (sign == true) {
		str = '-' + reverseString(str);
	}
	else{
		str = reverseString(str);
	}
	
	return str;
}

int main() {
	// string to int 
	string userString; 
	cout << "Please input a string value so that it could be converted to an integer " 
	<< endl;
	cin >> userString;
	cout << "You chose " << userString << " the integer of your string is: " 
	<< convertStringToInt(userString) << endl;
	
	int userNum; 
	cout << "Please input a integer value so that it could be converted to an string " << endl;
	cin >> userNum;
	cout << "You chose " << userNum << " the integer converted to string is: " 
	<< intToString(userNum) << endl;
	


return 0;
}