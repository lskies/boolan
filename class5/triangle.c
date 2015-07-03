class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if(row == 0) {
            return 0;
        }

        //初始化为最大值
        vector<int> total(row, INT_MAX);
        total[0] = triangle[0][0];
        int minTotal = INT_MAX;
        for(int i = 1; i < row; i++) {
            for(int j = i; j >= 0; j--) {
                if(j == 0) {
                    total[j] = total[j] + triangle[i][j];
                } else {
                    //上一层total[i]为INT_MAX，不会影响最小值
                    total[j] = min(total[j - 1], total[j]) + triangle[i][j];
                }
            }
        }
        for(int i = 0; i < row; i++) {
            minTotal = min(minTotal, total[i]);
        }
        return minTotal;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()) {
            return 0;
        }
        int row = triangle.size();
        vector<int> dp;
        dp.resize(row);
        //用最底层的数据初始化
        for(int i = 0; i < dp.size(); i++) {
            dp[i] = triangle[row-1][i];
        }

        for(int i = row - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
