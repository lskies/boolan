public class Solution {
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    public int majorityNumber(ArrayList<Integer> nums, int k) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for (Integer i : nums) {
            if (!map.containsKey(i)) {
                map.put(i, 1);
            } else {
                map.put(i, map.get(i) + 1);
            }
            
            if (map.size() >= k) {
                removeKey(map);
            }
        }
        if (map.size() == 0) {
            return Integer.MIN_VALUE;
        }
        int ans = 0;
        int maxKey = 0;
        int max = 0;
        Set<Integer> keySet = map.keySet();
        for (Integer i : keySet) {
            int count = 0;
            for (Integer j : nums) {
                if (i.equals(j)) {
                    count++;
                }
            }
            if (count > max) {
                max = count;
                maxKey = i;
                ans = count;
            }
        }
        
        return maxKey;
    }
    
    private void removeKey(Map<Integer, Integer> map) {
        Set<Integer> keySet = map.keySet();
        List<Integer> removeList = new ArrayList<>();
        for (Integer key : keySet) {
            if (map.get(key) == 1) {
                removeList.add(key);
            }
            else {
                map.put(key, map.get(key) - 1);
            }
        }
        for (Integer key : removeList) {
            map.remove(key);
        }
    }
}
