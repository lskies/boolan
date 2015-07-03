class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int m = INT_MIN;

        for(int i = 0; i < n; i++) {
            sum += A[i];
            m = max(m, sum);
            //如果sum小于0了，将sum重置为0，从i + 1再次开始计算
            if(sum < 0) {
                sum = 0;
            }
        }

        return m;
    }
};
