c class Solution {
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();

        if (root == null) {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        int currLevelNodeNum = 1;
        int nextLevelNodeNum = 0;

        while (currLevelNodeNum != 0) {
            ArrayList<Integer> currLevelResult = new ArrayList<Integer>();
            nextLevelNodeNum = 0;

            while (currLevelNodeNum != 0) {
                TreeNode node = queue.poll();

                currLevelNodeNum--;
                currLevelResult.add(node.val);

                if (node.left != null) {
                    queue.offer(node.left);
                    nextLevelNodeNum++;
                }

                if (node.right != null) {
                    queue.offer(node.right);
                    nextLevelNodeNum++;
                }
            }

            result.add(0, currLevelResult);
            currLevelNodeNum = nextLevelNodeNum;
        }
        return result;
    }
}
