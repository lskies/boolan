/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 
Your algorithm should run in O(n) complexity.
*/
/*
思路：开始是用数组，但是由于有负数，所以改用hashmap， num[i]为key。然后对每个值，往大和小分别查找，如果map里有，则说明是连续的，把这个值去掉，避免重复查找。
*/
import java.util.HashMap;
 
/*Longest Consecutive Sequence*/
public class longestConsecutive {
  public int longestConsecutive(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
    HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
    for (int i = 0; i < num.length; i++) {
      hm.put(num[i], 1);
    }
    int max = 1;
    for (int i = 0; i < num.length; i++) {
      int temp = num[i];
      int left = 1;
      while (hm.containsKey(temp-left)) {
        hm.remove(temp-left);
        left++;
      }
      int right = 1;
      while (hm.containsKey(temp+right)) {
        hm.remove(temp+right);
        right++;
      }
      max = Math.max(max, left+right-1);
    }
    return max;
    }
  public static void main(String[] args) {
    int [] num = {1, 0, -1};
    System.out.println(new longestConsecutive().longestConsecutive(num));
  }
}
