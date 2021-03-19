#include <iostream> //Include the Header library provides basic input and output services.

#include <cmath> //declares a set of functions to perform mathematical operations

using namespace std; // define the context in which names are defined.(it defines the scope)

const int A_CONSTANT = 3; //declare a integer constant and assigned the value

void functionA(int a[], int aNumber); //function declaration: named functionA which takes integer number and integer array argument having void as a return type

void functionB(int a[], int anotherNumber); //function declaration: named functionB which takes integer number and integer array argument having void as a return type

void functionC(const int anArray[], int aNumber); //function declaration: named functionC which takes integer number and constant integer array argument having void as a return type

void functionD(int &sum);//function declaration: named functionD which takes integer argument "&" denotes a reference instead of a pointer to an objec

int functionE(double number); //function declaration: named functionE which takes double datatype argument(parameter) with intger return type.

void functionF(int n); //function declaration: named functionF which takes integer as an argument and void return type

int main( ){ //Main Method declaration

int production[A_CONSTANT]; //integer array declaration which takes A_CONSTANT as a size of array

cout << "This program displays a graph showing\n" << "production for each factory in the company.\n";//cout is use for printing information

functionA(production, A_CONSTANT); //calling Function functionA and passing the parameters

functionB(production, A_CONSTANT); //calling Function functionB and passing the parameters

functionC(production, A_CONSTANT); //calling Function functionC and passing the parameters

return 0; //The return 0 means success and returning a non-zero number means failure.
  
} //main method ended

void functionA(int a[], int aNumber){ //method functionA

for (int someNumber = 1;someNumber <= aNumber; someNumber++){
cout << endl << "Enter production data for plant number " << someNumber << endl; //endl denotes the nextline
functionD(a[someNumber - 1]);//functio calling
}

}//end of functionA

void functionD(int& sum){ //method functionD

cout << "Enter number of units produced by each department.\n" << "Append a negative number to the end of the list.\n";//\n also denotes a newline
sum = 0;
int next;
cin >> next;//taking user input
while (next >= 0) {
sum = sum + next;
cin >> next;
}
cout << "Total = " << sum << endl;
  
}//end of functionD

void functionB(int a[], int anotherNumber){//method functionB

for (int index = 0; index < anotherNumber; index++){
a[index] = functionE(a[index]/1000.0);
}
  
}//end of functionB

int functionE(double number){ //method functionE
return static_cast<int>(floor(number + 0.5));
}//end of functionE


void functionC(const int anArray[], int aNumber){//method functionC
cout << "\nUnits produced in thousands of units:\n";
for (int someNumber = 1; someNumber <= aNumber; someNumber++){
cout << "Factory #" << someNumber << " ";
functionF(anArray[someNumber - 1]);
cout << endl;
}//end of for
}//end of functionC

void functionF(int n){//method functionF
for (int count = 1; count <= n; count++){
cout << "*";
}
}//end of functionF
