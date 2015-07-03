class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0) {
            return true;
        }

        int v = A[0];

        for(int i = 1; i < n; i++) {
            v--;
            if(v < 0) {
                return false;
            }

            if(v < A[i]) {
                v = A[i];
            }
        }
        return true;
    }
};
