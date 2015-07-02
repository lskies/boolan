// use 2 variables 
void printLevelOrder(BinaryTree *root) {
  if (!root) return;
  queue<BinaryTree*> nodesQueue;
  int nodesInCurrentLevel = 1;
  int nodesInNextLevel = 0;

  nodesQueue.push(root);
  while (!nodesQueue.empty()) {
    BinaryTree *currNode = nodesQueue.front();
    nodesQueue.pop();
    nodesInCurrentLevel--;
    if (currNode) {
      cout << currNode->data << " ";
      nodesQueue.push(currNode->left);
      nodesQueue.push(currNode->right);
      nodesInNextLevel += 2;
    }
    if (nodesInCurrentLevel == 0) {
      cout << endl;
      nodesInCurrentLevel = nodesInNextLevel;
      nodesInNextLevel = 0;
    }
  }
}

// use 2 queue
void printLevelOrder(BinaryTree *root) {
  if (!root) return;
  queue<BinaryTree*> currentLevel, nextLevel;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    BinaryTree *currNode = currentLevel.front();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->data << " ";
      nextLevel.push(currNode->left);
      nextLevel.push(currNode->right);
    }
    if (currentLevel.empty()) {
      cout << endl;
      swap(currentLevel, nextLevel);
    }
  }
}

