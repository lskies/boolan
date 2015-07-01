public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int m = matrix.length;
        int n = matrix[0].length;

        if (target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;


        int lower = 0;
        int upper = m*n -1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)>>1;
            if (target == matrix[mid%m][mid%n]) {
                return true;
            } else if (target < matrix[mid%m][mid%n]) {
                upper = mid-1;
            } else {
                lower = mid+1;
            }
        }

        return false;
    }
}
