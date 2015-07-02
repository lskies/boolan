class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> ret;
        if(num.size() == 0 || target < 0) //invalid corner case check
            return ret;
        vector<int> curr;
        sort(num.begin(), num.end());
        BackTracking(ret,curr,num,target,0);
        return ret;
    }

    void BackTracking(vector<vector<int>>& ret, vector<int> curr, vector<int> num, int target, int level)
    {
        if(target == 0)
        {
            ret.push_back(curr);
            return;
        }
        else if(target < 0)
            return;
        for(int i = level; i < num.size(); ++i)
        {
            target -= num[i];
            curr.push_back(num[i]);
            BackTracking(ret,curr,num,target,i+1);
            curr.pop_back();
            target += num[i];
            while(i < num.size()-1 && num[i] == num[i+1]) //we add this while loop is to skip the duplication result
                ++i;
        }
    }

};
