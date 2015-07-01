int level(TreeNode *root){
    if(root ==  NULL)
        return 0;
    return max(level(root->left), level(root->right)) + 1;
}
bool isBalanced(TreeNode* root){
    if(root ==  NULL)
        return true;
    int factor = abs(level(root->left) - level(root->right));
    return factor < 2 && isBalanced(root->right) && isBalanced(root->left);
}
