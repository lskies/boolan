bool isDummyNode(TreeNode *node)
{
    return (node->left == node);
}

vector<list<TreeNode *>> linkedListsFromTree(TreeNode *root)
{
    vector<list<TreeNode *>> result;
    list<TreeNode *> levelList;
    queue<TreeNode *> nodeQueue;
    TreeNode *currentNode;

    TreeNode dummyNode;
    dummyNode.left = &dummyNode;


    if (!root) {
        return answer;
    }

    nodeQueue.push(&dummyNode);
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        currentNode = nodeQueue.front();
        if (isDummyNode(currentNode)) {
            if (!levelList.empty()) {
                answer.push_back(levelList);
                levelList.clear();
            }
            nodeQueue.pop();
            if (nodeQueue.empty()) {
                break;
            } else {
                nodeQueue.push(&dummyNode);
            }

        } else {
            levelList.push_back(currentNode);
            if (currentNode->left) {
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                nodeQueue.push(currentNode->right);
            }
            nodeQueue.pop();
        }
    }

    return result;
}

