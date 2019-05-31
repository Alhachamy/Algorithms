package alhachamy;
/**
 * @author Ali A
 * @brief java implementation of a Merge Sort on an integer array
 *        the array is populated with random integers and passed
 *        to a recursive merge sort function
 */

import java.util.Random;

public class Main {

    public static void main(String[] args) {
        /** array, size, and random object instantiation*/
        final int SIZE = 100;
        Random rand = new Random();
        int [] arr = new int[SIZE];
        /** populating the array with random integers*/
        for(int i = 0; i < SIZE; i++){
            arr[i] = rand.nextInt(500);
        }
        /** print unsorted array*/
        System.out.println("Unsorted Array\n====================");
        printArray(arr);
        /** call mergeSort method*/
        mergeSort(arr, 0, arr.length-1);
        /** print sorted array*/
        System.out.println("Sorted Array\n====================");
        printArray(arr);
    }

    /**
     * @brief recursive merge sort function
     * @param a , the array
     * @param begin , array beginning
     * @param end, array ending
     */
    private static void mergeSort(int[] a, int begin, int end){

        if(begin < end){
            int mid = (begin+end)/2;
            mergeSort(a,begin,mid);
            mergeSort(a,mid+1,end);
            merge(a,begin,mid,end);
        }
    }

    /**
     * @brief main merge subroutine, this will take an array and split it
     *        in two and merge values back into the main output array.
     * @param arr , the array
     * @param begin , array beginning
     * @param mid , array midpoint
     * @param end , array ending
     */
    private static void merge(int[] arr, int begin, int mid, int end){
        /** n1 and n2 are the sizes for the new sub arrays*/
        int n1 = mid - begin +1;
        int n2 = end-mid;
        /** new right and left sub arrays with size n1 and n2*/
        int[] left = new int[n1+1];
        int[] right = new int[n2+1];

        /** populate both suba rrays*/
        for(int i = 0; i < n1;i++){
            left[i] = arr[begin+i];
        }

        for(int j = 0; j < n2; j++){
            right[j] = arr[mid+j+1];
        }
        /** set the sentinel value for the arrays*/
        left[n1] = Integer.MAX_VALUE;
        right[n2] = Integer.MAX_VALUE;
        /** set new index*/
        int i = 0;
        int j = 0;
        /** compare and push values back to output array*/
        for(int k = begin; k <= end;k++){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
            }else{
                arr[k] = right[j];
                j++;
            }
        }
    }

    /**
     * @brief method that prints the array
     * @param a , the array
     */
    private static void printArray(int[] a){
        for(int i = 0; i < a.length; i++){
            System.out.println(a[i]);
        }
    }
}
