bool helper(TreeNode *root, int min, int max){
    if(!root) return true;
    if((root->val < max || (root->val == INT_MAX && root->right == NULL)) &&
        (root->val > min || (root->val == INT_MIN && root->left == NULL)) &&
        helper(root->left, min, root->val) &&
        helper(root->right, root->val, max))
            return true;
    return false;
}

bool isValidBST(TreeNode *root) {
    return helper(root, INT_MIN, INT_MAX);
}

