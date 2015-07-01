TreeNode *inOrderSuccessor(TreeNode *node, TreeNode *root)
{
    if (!node) {
        return NULL;
    }
    if (node->right) {
        return leftMostNode(node->right);
    }

    TreeNode *successor = NULL;
    while (root) {
        if (root->val > node->val) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

