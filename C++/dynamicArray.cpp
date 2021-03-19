#include <iostream>
#include <string>

using namespace std;

typedef int* IntPtr;

int main() {
  int size = 10;
  const int INCREMENT = 5;
  int val = 0;
  int count = 0;
  IntPtr numbers = new int[size];

  cout << "Enter a number of positive integers "
       << "(-1 when done): " << endl;
  cin >> val;
  while (val != -1) {
    numbers[count] = val;
    count++;
    if (count == size) {
      //Create a larger array
      IntPtr temp = new int[size+INCREMENT];
      for (int i=0; i<size; i++) {
        temp[i] = numbers[i];
      }
      delete[] numbers;
      numbers = temp;
      size += INCREMENT;
    }
    //read the next value
    cin >> val;
  }


  for (int i = 0; i < count; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  delete[] numbers;

  return 0;
}