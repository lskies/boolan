TreeNode* helper(vector<int>num, int first, int last){
    if(first > last){
        return NULL;
    }
    if (first == last) {
        TreeNode* parent = new TreeNode(num[first]);
        return parent;
    }
    int mid = (first + last) / 2;
    TreeNode *leftchild = helper(num, first, mid - 1);
    TreeNode *rightchild = helper(num, mid + 1, last);
    TreeNode *parent = new TreeNode(num[mid]);
    parent->left = leftchild;
    parent->right = rightchild;
    return parent;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    if(num.size() == 0)
        return NULL;
    if(num.size() == 1){
        TreeNode* parent = new TreeNode(num[0]);
        return parent;
    }
    int first = 0;
    int last = (int)num.size() - 1;
    return helper(num, first, last);
}

