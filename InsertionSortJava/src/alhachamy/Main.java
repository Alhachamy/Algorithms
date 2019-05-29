package alhachamy;

// Name: Ali A
// Brief: Java implementation of insertion sort

public class Main {

    public static void main(String[] args) {
        // init array
        int[] array = {6,34,73,11,2,55,64,100,25};

        // print array
        System.out.println("Unsorted Array\n================");
        print(array);

        // pass array to insertion sort method
        insertionSort(array);
    }

    // method that prints the array
    public static void print(int[] a){
        for(int i = 0; i < a.length; i++){
            System.out.println(a[i]);
        }
    }

    // Brief: Insertion sort method for an integer array
    // Param: integer array 'a'
    // Return: void
    public static void insertionSort(int[] a){
        // key
        int key;
        // temp
        int temp;
        // iterate through array
        for(int i = 1; i < a.length; i++){
            // set current key
            key = a[i];
            // set one behind key
            temp = i-1;

            // sort the subarray
            while(temp >= 0 && a[temp] > key){
                a[temp+1] = a[temp];
                temp--;
            }
            // move index
            a[temp + 1] = key;
        }
        // print sorted array
        System.out.println("\nSorted Array\n================");
        print(a);
    }
}
