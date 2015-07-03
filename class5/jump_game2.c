class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int cur = 0;
        int next = 0;

        int i = 0;
        while(i < n){
            if(cur >= n - 1) {
                break;
            }

            while(i <= cur) {
                //更新最远达到点
                next = max(next, A[i] + i);
                i++;
            }
            step++;
            cur = next;
        }

        return step;
    }
};
