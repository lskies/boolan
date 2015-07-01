void printLevelOrderZigZag(BinaryTree *root) {
  stack<BinaryTree*> currentLevel, nextLevel;
  bool leftToRight = true;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    BinaryTree *currNode = currentLevel.top();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->data << " ";
      if (leftToRight) {
        nextLevel.push(currNode->left);
        nextLevel.push(currNode->right);
      } else {
        nextLevel.push(currNode->right);
        nextLevel.push(currNode->left);
      }
    }
    if (currentLevel.empty()) {
      cout << endl;
      leftToRight = !leftToRight;
      swap(currentLevel, nextLevel);
    }
  }
}
