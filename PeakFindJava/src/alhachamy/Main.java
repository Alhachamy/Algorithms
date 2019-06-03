package alhachamy;

/**
 * @author Ali A
 * @brief Java Implementation of a matrix peak find. Given a matrix, we binary
 *        search the largest element in the column, we then compare that value
 *        to its neighbors. If the element is greater than or equal to its neighbors,
 *        it is a peak, otherwise the greater neighbor element becomes the new midpoint
 *        and we recursively search again until we find a peak. A peak doesn't have to
 *        be the largest element in the matrix, it has to be greater than or equal to its
 *        neighbors. Once that condition is satisfied, the peak will be returned.
 */
public class Main {
    /**peak value */
    private static int max;

    public static void main(String[] args) {
        /**define matrix dimensions*/
        final int ROW = 11;
        final int COL = 11;
        /**
         * populate the matrix, the peaks in this matrix are:
         * there are multiple peaks in this matrix, and multiple
         * peaks on the same columns
         */
        int[][] matrix = {
                { 4,  5,  6,  7,  8,  7,  6,  5,  4,  3,  2},
                { 5,  6,  7,  8,  9,  8,  7,  6,  5,  4,  3},
                { 6,  7,  8,  9, 10,  9,  8,  7,  6,  5,  4},
                { 7,  8,  9, 13, 11, 10,  9,  8,  7,  6,  5},
                { 8,  9,  7, 10,  6,  3, 10,  9,  8,  7,  6},
                { 7,  8,  9, 10, 11, 10,  9,  8,  7,  6,  5},
                { 6,  7,  8,  9, 10,  9,  8,  7,  6,  5,  4},
                { 5,  6,  7,  8,  9,  8,  7,  6,  5,  4,  3},
                { 4,  5,  6, 14,  8,  7,  6,  5,  4,  3,  2},
                { 3,  4,  5,  6,  7,  6,  5,  4,  3,  2,  1},
                { 2,  3,  4,  5,  6,  5,  4,  3,  2,  1,  0}
                };

        /** print the peak */
        System.out.println("The peak is: " + findPeak(matrix,ROW,COL,(COL/2)));
    }

    /**
     * @brief store the maximum value in a row and return its index
     *        element in the matrix
     * @param a, the matrix
     * @param row, row value
     * @param mid, midpoint, col/2
     * @return row index
     */
    public static int findPeakIndex(int[][] a, int row, int mid){
        /** init an the index*/
        int index = 0;
        /** iterate through the mid point of the matrix and store the max
         * value in max value and its index
         */
        for(int i = 0; i < row; i++){
            if(max < a[i][mid]){
                max = a[i][mid];
                index = i;
            }
        }

        return index;
    }

    /**
     * @brief recursively find a peak by comparing the current peak candidate to its neighbors
     *        if the members are bigger, we move the index left or right and discard half the
     *        matrix
     * @param a , the matrix
     * @param row, the rows
     * @param col, the columns
     * @param mid, the mid
     * @return peak, the integer peak value
     */
    public static int findPeak(int[][] a, int row, int col, int mid){

        /** set init the max index and peak*/
        int maxIndex = findPeakIndex(a, row, mid);
        int peak = 0;
        /** check bounds*/
        if(mid == 0 || mid == col-1){
            return max;
        }
        /** if the current value is >= its neighbors, its a peak.
         *  otherwise move the mid point left or right and compare
         *  the next value to its neighbors
         **/
        if(max >= a[maxIndex][mid-1] && max>= a[maxIndex][mid + 1]){
            return max;
        }
        else if(max < a[maxIndex][mid-1]){
            peak = findPeak(a,row,col,--mid);

        }
        else if(max < a[maxIndex][mid+1]){
            peak = findPeak(a, row, col,++mid);
        }
        return peak;
    }

}
