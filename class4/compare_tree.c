int sameTree(struct node* a, struct node* b) {
  // 1. both empty -> true
  if (a==NULL && b==NULL) {
      return true;
  }
  // 2. both non-empty -> compare them
  else if (a!=NULL && b!=NULL) {
    return
      a->data == b->data &&
      sameTree(a->left, b->left) &&
      sameTree(a->right, b->right)
    ;
  }
  // 3. one empty, one not -> false
  else { 
      return false;
  }
}   
