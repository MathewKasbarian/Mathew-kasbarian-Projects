#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap(int *x , int *y){
int temp = *x ;
*x = *y;
*y = temp;


}
void bubbleSort(int* number, int n){
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++ ) {
            if(number[j] > number[j+1]) {
                swap(&number[j+1], &number[j]);
            }
        }
    }
}



void randomizeArray(int* number, int n) {
    srand(10);
    for(int i = 0; i < n; ++i) {
        int r = rand()%100;
        swap(&number[i],&number[r]);
    }
}


int main(){

for ( int x = 1000;x<=10000;x=x*10 ) {

    int arr[x];
    int n =x;
    int temp = n;
    for(int i = 0; i < n; ++i) {
        arr[i] = temp--;
    }
    clock_t t1 , t2 ;
    randomizeArray(arr,n);
    t1 = clock();
    bubbleSort(arr, n);
    t2 = clock();
        printf("The amount of time taken to execute for x = %d is %lf \n",x ,(t2-t1)/(float)CLOCKS_PER_SEC);
    
    

}
    return 0;
}

