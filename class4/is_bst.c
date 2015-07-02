bool helper(TreeNode *root, int min, int max){
    if(!root) return true;
    if (root->val >= max || root->val <= min) {
        return false;
    }

    return dfs(root->left, min, root->val) 
       && dfs(root->right, root->val, max);
}

bool isValidBST(TreeNode *root) {
    return dfs(root, INT_MIN, INT_MAX);
}
