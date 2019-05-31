#include <iostream>
#include <ctime>
#include <cstdlib>
// prototypes
void merge(int a[], int begin, int mid, int end);
void mergeSort(int a[], int begin, int end);
void printArray(int a[], int s);
// sentinel value should always be higher than highest array element
const int SENTINEL = 1000000;

int main() {
    // init array and its size
    const int SIZE = 100;
    int array[SIZE];
    // random time seed
    srand(time(0));
    // populate array
    for(int i = 0; i < SIZE; i++){
        array[i] = 1 + (rand() % 1000);
    }
    // print unsorted array
    std::cout << "Unsorted Array\n=================" << std::endl;
    printArray(array,SIZE);
    // call mergeSort function
    mergeSort(array,0, SIZE);
    // print sorted array
    std::cout << "Sorted Array\n=================" << std::endl;
    printArray(array, SIZE);


    return 0;
}

// Brief: merge subroutine
// Param: integer array "a[]"
//        array properties
//        "begin" integer starting point of the array which is 0
//        "mid" integer halfway point of the array which is size/2
//        "end" integer endpoint of array which is the array size
// Return: void
void merge(int a[], int begin, int mid, int end){
    // set subarray sizes
    int n1 = mid-begin + 1;
    int n2 = end-mid;
    // init new arrays
    int left[n1 + 1];
    int right[n2 + 1];
    // populate left array
    for(int i = 0; i < n1; i++){
        left[i] = a[begin+i-1];
    }
    // populate right array
    for(int j = 0; j < n2; j++){
        right[j] = a[mid+j];
    }
    // set sentinal values
    left[n1] = SENTINEL;
    right[n2] = SENTINEL;
    // new indicies
    int i = 0;
    int j = 0;
    // push values to the output array
    for(int k = begin - 1; k < end; k++){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
    }

}

// Brief: recursive mergeSort function
// Param: integer array "a[]"
//        integer "begin" , starting point (0)
//        integer "end" , ending point (array size)
void mergeSort(int a[], int begin, int end) {
    // init mid
    int mid = 0;
    // set mid
    if (begin < end) {
        mid = (begin+end) / 2;
        // recursive mergeSort first half
        mergeSort(a, begin, mid);
        // recursive mergeSort second half
        mergeSort(a, mid + 1, end);
        // call merge subroutine
        merge(a, begin, mid, end);
    }
}
// Function that simply prints array
void printArray(int a[], int s){

    for(int i = 0; i < s; i++){
        std::cout << a[i] << std::endl;
    }
}