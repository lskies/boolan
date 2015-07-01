void pathSumHelper(vector<int> path, vector<vector<int>> &result, TreeNode *root, int sum){
    if(root == NULL)
        return;
    path.push_back(root->val);
    if(root->val == sum){
        answer.push_back(path);
    }
    pathSumHelper(path,answer,root->left, sum - root->val);
    pathSumHelper(path,answer,root->right, sum - root->val);
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<int> path;
    vector<vector<int>> result;
    pathSumHelper(path, result, root, sum);
    return result;
}

