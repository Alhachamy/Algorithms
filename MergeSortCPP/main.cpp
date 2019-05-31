#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>


void merge(int a[], int begin, int mid, int end);
void mergeSort(int a[], int begin, int end);
void printArray(int a[], int s);

int main() {
    // init array and its size
    const int SIZE = 100;
    int array[SIZE];
    // random time seed
    srand(time(0));
    // populate array
    for(int i = 0; i < SIZE-1; i++){
        array[i] = 1 + (rand() % 600);
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

/**
 * @brief merge subroutine
 * @param a , the array itself
 * @param begin , the beginning of the array
 * @param mid , the midpoint of the array
 * @param end , the end of the array
 * @return void
 */

void merge(int a[], int begin, int mid, int end){
    // set subarray sizes
    int n1 = mid-begin + 1;
    int n2 = end-mid;
    // init new arrays
    int left[n1+1];
    int right[n2+1];
    // populate left array
    for(int i = 0; i < n1; i++){
        left[i] = a[begin+i];
    }
    // populate right array
    for(int j = 0; j < n2; j++){
        right[j] = a[mid+j+1];
    }
    // set sentinal values
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    // new indicies
    int i = 0;
    int j = 0;
    // push values to the output array
    for(int k = begin; k <= end; k++){
        if(left[i] < right[j]){
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
    }

}

/**
 * @brief recursive mergeSort function
 * @param a , the array
 * @param begin , beginning of the array
 * @param end , ending of the array, which is array size
 * @return void
 */

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
/**
 * @brief prints array
 * @param a , array
 * @param s , size
 */
void printArray(int a[], int s){

    for(int i = 0; i < s; i++){
        std::cout << a[i] << std::endl;
    }
}
