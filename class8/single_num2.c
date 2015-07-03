class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        if (A.empty()) {
            return 0;
        }

        int result = 0, bit_i_sum = 0;

        for (int i = 0; i != 8 * sizeof(int); ++i) {
            bit_i_sum = 0;
            for (int j = 0; j != A.size(); ++j) {
                // get the *i*th bit of A
                bit_i_sum += ((A[j] >> i) & 1);
            }
            // set the *i*th bit of result
            result |= ((bit_i_sum % 3) << i);
        }

        return result;
    }
};
