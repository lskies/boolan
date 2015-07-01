int isBalancedHelper(TreeNode *root) {
    if (root == NULL) {
       return 0;
    }
    int leftHeight = isBalance(root->left);
    if (leftHeight == INBALANCE) {
        return INBALANCE;
    }
    int rightHeight = isBalance(root->right);
    if (rightHeight == INBALANCE) {
        return INBALANCE;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return INBALANCE;
    }

    return max(leftHeight, rightHeight) + 1;    // return height
}

bool isBalancedTree(TreeNode *root) {
    return (isBalancedHelper(root) != INBALANCE)
}

