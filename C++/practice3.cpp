#include <iostream> 

using namespace std;

void rotate(int array[], int n, int d) {
	
	int i = 0;
	int j = d-1;
	
	while (i < j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		
		i++;
		j--;
	}
	
	i = d;
	j = n-1;
	
	while (i < j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		
		i++;
		j--;
		
	}
	
	i = 0;
	j=n-1;
	
	while (i < j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		
		i++;
		j--;
	}
		
}

int main() {
	
int array{6}= {1,2,3,4,5,6};
	
	int n = 6;
	
	for (int i = 0; i < n; i++) {
	cout << array[i] << " ";
	}
	
	int d = 2;
	rotate(array, n, d);
	
	for (int i = 0; i < n; i++) {
		cout << array[i] << " " ;
	}
	
	
	
	
	return 0;	
	
}