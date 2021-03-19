#include <iostream>

using namespace std;

typedef in* IntPtr;

double out_of_order(double a[]);

int main() {
	
	double a[10] = {1.2, 2.1, 3.3, 3.5, 4.5, 7.9, 5.4, 8.7, 9.9, 1.0};
	
	
	
	return 0;
}
 double out_of_order(double a[] {
	int SIZE = 10
	for (int i = 0; i < size; i++) {
		if (i<= i+1){
			return -1;
		}
		else {
			return i;
		}
	}
	
	 
 }
	 
	 
	 
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