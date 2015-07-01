TreeNode* search_tree_node_with_ancestors(TreeNode* root, int value, vector<TreeNode*>& ancestors)
{
    if (root == NULL) return NULL;
    if (root->value == value) {
        ancestors.push_back(root);
        return root;
    }
    else {
        ancestors.push_back(root);
        TreeNode* tn = search_tree_node_with_ancestors(root->left, value, ancestors);
        if (tn != NULL) return tn;
        tn = search_tree_node_with_ancestors(root->right, value, ancestors);
        if (tn != NULL) return tn;
        ancestors.pop_back();
        return NULL;
    }
}

TreeNode* find_lowest_common_ancestor(TreeNode* root, int val1, int val2) {
    vector<TreeNode*> ancestor1;
    TreeNode* n1 = search_tree_node_with_ancestors(root, val1, ancestor1);
    vector<TreeNode*> ancestor2;
    TreeNode* n2 = search_tree_node_with_ancestors(root, val2, ancestor2);
    int minLen = min(ancestor1.size(), ancestor2.size());
    for (int i = 1; i < minLen; ++i) {
        if (ancestor1[i] != ancestor2[i])
            return ancestor1[i-1];
    }
    return ancestor1.size() > ancestor2.size() ? ancestor2[minLen - 1] : ancestor2[minLen - 1];
}
