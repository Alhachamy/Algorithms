// Author: Ali A
// Brief: Simple insertion sort implementation

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// array size constant
#define SIZE 100
// function prototype
void insertionSort(int a[]);

int main() {

    // declare array
    int array[SIZE];
    // random number seeding
    srand(time(NULL));

    // populate array with random integers
    for(size_t i = 0; i < SIZE; i++){
        array[i] = 1 + (rand() % 100);
    }

    // print unsorted array
    puts("Unsorted array: ");
    for(size_t i = 0; i < SIZE; i++){
        printf("%d\n", array[i]);
    }

    // pass array to sorting function
    insertionSort(array);

    // print sorted array
    puts("\nSorted array: ");
    for(size_t i = 0; i < SIZE; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}

// Brief: insertion sort for an array of integers
// Param: a[] integer array
// return: void
void insertionSort(int a[]){
    // index
    int key;
    // temp value
    int temp;
    // iterate through the array
    for(int i = 1; i < SIZE; i++){
        // set the index
        key = a[i];
        // set to one behind the index
        temp = i - 1;
        // swap
        while(temp >= 0 && a[temp] > key){
            a[temp + 1] = a[temp];
            temp--;
        } // end while
        // move index
        a[temp + 1] = key;
    } // end for
} // end function