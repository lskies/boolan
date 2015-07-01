// preorder and inorder rebuild
TreeNode* rebuild(char *pstr, char *istr, int n) {
    if (n <= 0)
        return NULL;

    TreeNode* root = new TreeNode;
    root->data = *pstr;

    char* iter;
    for (iter = istr; iter < istr + n; iter++) {
        if (*iter == *pstr)
            break;
    }

    int k = iter - istr;
    root->left = rebuild(pstr + 1, istr, k);
    root->right = rebuild(pstr + k + 1, iter + 1, n - k - 1);

    return root;
}
