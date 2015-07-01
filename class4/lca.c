TreeNode *commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    if (covers(root->left, p) && covers(root->left, q)) {
        return commonAncestor(root->left, q, p);
    }
    if (covers(root->right, p) && covers(root->right, q)) {
        return commonAncestor(root->right, q, p);
    }
    return root;
}

bool covers(TreeNode *root, TreeNode *p){
    if (root == NULL) {
        return false;
    }
    if (root == p) {
        return true;
    }
    return covers(root->left, p) || covers(root->right, p);
}

