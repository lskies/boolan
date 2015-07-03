class Solution {
public:
    int majorityNumber(vector<int> nums) {
        int candidate, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count ++;
            } else {
                if (candidate == nums[i]) {
                    count ++;
                } else {
                    count --;
                }
            }
        }
        return candidate;
    }
};
