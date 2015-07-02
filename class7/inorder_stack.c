void inOrderTraversal(TreeNode *root) {
    if(root == NULL)
        return;
    stack<TreeNode *> st;
    while(!st.empty() || root ) {
        if(root) {
            st.push(root);
            root = root->left;
        } else {
            root = st.top();
            st.pop();
            visit( root );
            root = root->right;
        }
    }
}

