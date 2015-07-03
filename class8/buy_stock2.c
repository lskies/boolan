class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = (int)prices.size();
        if(len <= 1) {
            return 0;
        }

        int sum = 0;
        for(int i = 1; i < len; i++) {
            if(prices[i] - prices[i - 1] > 0) {
                sum += prices[i] - prices[i - 1];
            }
        }

        return sum;
    }
};
