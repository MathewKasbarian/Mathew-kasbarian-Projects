#include <iostream>

using namespace std;

class Person {
	// member variables 
	private:
		string firstName;
		string lastName;
		int age;
		
	
	//member functions 
	public:
		Person();
		Person(string firstName, string lastName, int age);
		~Person ();
		//getter & setter functions 
		void setFName(string f) {firstName = f;}
		string getFName() {return firstName;}
	
		void setLName(string l) {lastName = l;}
		string getLName() {return lastName;}
		
		void setAge(int a ) {age = a;}
		int getAge() {return age;}

//define default constructor
Person::Person() {
	firstName = "FNU";
	lastName = "LNU";
	age = -1;
	
	
	
}

Person::Person(string firstName, string lastName, int age) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	
}

Person::~Person() {
	cout << "destructor calling" << endl;
}

}

int main() {
	Person *p1 = new Person();
	cout << "object p1: " << endl;
	cout << "first name: " << p1->getFName() << " last name: " << p1->getLName() << endl;
	cout << "age: " << p1->getAge() << endl;
	
	Person *p2 = new Person("john", "johnLastName" , 18); 
	cout << endl << "object p2: " << endl;
	cout << "first name: " << p2->getFName() << " last name: " << p2->getLName() << endl;
	cout << "age: " << p2->getAge() << endl<< endl;
	
	return 0;
	
}