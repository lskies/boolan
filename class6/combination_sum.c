class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ret;
        if(n <= 0) //corner case invalid check
            return ret;

        vector<int> curr;
        DFS(ret,curr, n, k, 1); //we pass ret as reference at here
        return ret;
    }

    void DFS(vector<vector<int>>& ret, vector<int> curr, int n, int k, int level)
    {
        if(curr.size() == k)
        {
            ret.push_back(curr);
            return;
        }
        if(curr.size() > k)  // consider this check to save run time
            return;

        for(int i = level; i <= n; ++i)
        {
            curr.push_back(i);
            DFS(ret,curr,n,k,i+1);
            curr.pop_back();
        }
    }


};
