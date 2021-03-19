#include <iostream>
#include <string>

using namespace std;

//Function declarations
int valueSquared(int num);
int refSquared(const int &num);

int main() {
  int n = 1;
  int nsquared = 1;
  cout << "Enter an integer: ";
  cin >> n;

  cout << "memory address of n is " << &n << endl;

  cout << "CALL-BY-VALUE Example" << endl;
  //square n by calling valueSquared function
  nsquared = valueSquared(n);
  cout << "The square of " << n << " is "
       << nsquared << endl;

  cout << "CALL-BY-REFERENCE Example" << endl;
  //square n by calling valueSquared function
  nsquared = refSquared(n);
  cout << "The square of " << n << " is "
       << nsquared << endl;

  return 0;

}

//Function definitions
int valueSquared(int num) {
  cout << "memory address of num in valueSquared is "
       << &num << endl;

  num = num * num;
  return num;
}

int refSquared(const int &num) {
  cout << "memory address of num in refSquared is "
       << &num << endl;

  int num2 = num * num;
  return num2;
}