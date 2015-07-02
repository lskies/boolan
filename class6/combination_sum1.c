class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        //corner case invalid check
        if(candidates.size() == 0 || target < 0)
            return ret;
        vector<int> curr;
        sort(candidates.begin(),candidates.end()); //because the requirments need the elements should be in non-descending order
        BackTracking(ret,curr,candidates,target,0);
        return ret;
    }

    /* we use reference at here because the function return type is 0, make the code understand easily */
    void BackTracking(vector<vector<int>>& ret, vector<int> curr, vector<int> candidates, int target, int level)
    {
        if(target == 0)
        {
            ret.push_back(curr);
            return;
        }
        else if(target < 0) //save time
            return;

        for(int i = level; i < candidates.size(); ++i)
        {
            target -= candidates[i];
            curr.push_back(candidates[i]);
            BackTracking(ret,curr,candidates,target,i); //unlike combination, we do not use i+1 because we can use the same number multiple times.
            curr.pop_back();
            target += candidates[i];
        }
    }

};
