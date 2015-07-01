bool subTree(TreeNode *root1, TreeNode *root2){
    if (root2 == NULL) {
        return true;
    }
    if (root1 == NULL) { //we have exhauste the root1 already
        return false;
    }
    if (root1->val == root2->val) {
        if (matchTree(root1, root2)) {
            return true;
        }
    }
    return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
}

bool matchTree(TreeNode *root1, TreeNode *root2){
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return matchTree(root1->left, root2->left) &&
        matchTree(root1->right, root2->right);
}

