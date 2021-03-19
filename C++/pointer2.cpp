#include <iostream>
#include <string>

using namespace std;

//define our own type!
typedef int* IntPtr;

void myFunction(IntPtr p2);

int main() {
  IntPtr p1; //same as int *p1;
             //pointer to an integer
             // (called a pointer variable)
  int t = 20; //an automatic variable
              //(also called an ordinary variable)

  //point p1 to t's address
  p1 = &t;

  myFunction(p1);

  //display value and address of pointer variable
  cout << "value: *p1 = " << *p1 << "\t"
       << "address: p1 = " << p1 << endl;

  //display value and address of ordinary variable
  cout << "value: t = " << t << "\t"
       << "address: &t = " << &t << endl;

  return 0;
}

void myFunction(IntPtr p2) {
  *p2 = 10;

  int x = 5;
  p2 = &x;
  cout << "value: *p2 = " << *p2 << "\t"
       << "address: p2 = " << p2 << endl;
  cout << "value: x = " << x << "\t"
      << "address: &x = " << &x << endl;

}