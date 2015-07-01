TreeNode *leftMostNode(TreeNode *node) {
    if (!node) {
        return NULL;
    }
    while (node->left) {
        node = node->left;
    }
    return node;
}

bool isLeftChild(TreeNode *node, TreeNode *parent) {
    return (parent->left == node);
}

TreeNode *inOrderSuccessor(TreeNode *node) {
    if (!node) {
        return NULL;
    }
    if (node->right) {
        return leftMostNode(node->right);
    }

    TreeNode *parent = node->parent;
    while (parent && !isLeftChild(node, parent)) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}

