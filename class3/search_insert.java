public class Solution {
    public int searchInsert(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int begin = 0;
        int end = A.length - 1;
        while (begin <= end) {
            int mid = begin + (end-begin)/2;
            if (A[mid] == target) return mid;
            if (A[mid] > target)
                end = mid -1;
            else
                begin = mid +1;
        }
        if (end == -1)
            return 0;

        if (A[end] < target)
            return end + 1;
        else
            return end;
    }
}
