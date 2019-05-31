// Name: Ali A
// Brief: Simple merge sort implementation in C

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

// size of the array and sentinel value
#define SIZE 100

void print(int a[]);
void merge(int a[], int begin, int mid, int end);
void mergeSort(int a[], int begin, int end);

int main() {
    // time seed for random numbers
    srand(time(NULL));
    // init array
    int array[SIZE];
    // populate the array with random integers
    for(size_t i = 0; i < SIZE; i++) {
        array[i] = 1 + (rand() % 500);
    }
    //print unsorted array
    printf("Unsorted Array: \n=============\n");
    print(array);
    // call mergeSort function, pass it the array and its properties
    mergeSort(array,0, SIZE-1);
    // print sorted array
    printf("Unsorted Array: \n=============\n");
    print(array);

    return 0;
}

// Function that simply prints the array
void print(int a[]){
    for(size_t i = 0; i < SIZE; i++){
        printf("%d\n", a[i]);
    }
}
// Brief: merge subroutine
// Param: integer array "a[]"
//        array properties
//        "begin" integer starting point of the array which is 0
//        "mid" integer halfway point of the array which is size/2
//        "end" integer endpoint of array which is the array size
// Return: void
void merge(int a[], int begin, int mid, int end){
    // create two new array sizes for the sub arrays
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    // init two arrays and give them the sizes above
    int left[n1+1];
    int right[n2+1];
    // iterate through the new left array and populate it
    for(int i = 0; i < n1; i++){
        left[i] = a[begin + i];
    }
    // iterate through the new right array and populate it
    for(int j = 0; j < n2; j++){
        right[j] = a[mid+j+1];
    }

    // Set the sentinel value
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    // setting new indices
    int i = 0;
    int j = 0;
    // compare the values in the sub arrays and send them to
    // the initial output array
    for(int k = begin; k <= end; k++){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
    }
}
// Brief: recursive mergeSort function
// Param: integer array "a[]"
//        integer "begin" , starting point (0)
//        integer "end" , ending point (array size)
void mergeSort(int a[], int begin, int end){
    // init a midpoint
    int mid = 0;
    // set the midpoint
    if(begin < end){
        mid = (begin+end)/2;
        // recursive mergeSort first half
        mergeSort(a,begin,mid);
        // recursive mergeSort second half
        mergeSort(a,mid+1,end);
        // call merge subroutine
        merge(a,begin,mid,end);
    }
}
