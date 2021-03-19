#include <iostream>
#include<string>
using namespace std;

int main(){
	
	string Firstname;
	string Lastname;
	int year;
	int wage;
	
	cout << "Job applicant's name: " << endl;
	cin  >> Firstname >> Lastname;
	
	cout << "Job applicant's birth year: " << endl;
	cin >> year;
	
	int age =2019 - year;
	
	cout << "Job applicant's hourly wage: " << endl;
	cin >> wage;
	
	cout <<Firstname << " " << Lastname << " is " <<age<< " years old and requests an hourly wage of $" << wage <<".00."<<endl;
	
	return 0;

}