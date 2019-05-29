// Author: Ali A
// Brief: C++ implementation of insertion sort

#include <iostream>
#include <ctime>
#include <cstdlib>

void insertionSort(int a[],int size);

int main() {
    // declare array and its size.
    const int SIZE = 100;
    int array[SIZE];

    // generate random numbers
    srand(time(0));
    // populate array with random numbers
    for(int i = 0; i < SIZE; i++){
        array[i] = 1 + (rand() % 100);
    }

    // print unsorted array
    std::cout << "Unsorted array: " << std::endl;

    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << std::endl;
    }

    // pass array to insertion sort function
    insertionSort(array, SIZE);

    // print sorted output
    std::cout << "Sorted array: " << std::endl;

    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << std::endl;
    }

    return 0;
}

// Brief: function that insertion sorts an array of integers
// Param: a[] <- integer array
//        size <- array size
// Return: void
void insertionSort(int a[],int size){
    // key
    int key;
    // temp
    int temp;

    // iterate through the array
    for(int i = 1; i < size; i++){
        // set index
        key = a[i];
        // set to one less than the index
        temp = i - 1;
        // sort the subarray
        while(temp >= 0 && a[temp] > key){
            a[temp + 1] = a[temp];
            temp--;
        }
        // increment
        a[temp + 1] = key;
    }
}