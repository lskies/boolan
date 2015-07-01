public void iterativePreorder(Node root) {
   Stack nodes = new Stack();
   nodes.push(root);
   Node currentNode;
   while (! nodes.isEmpty()){
      currentNode = nodes.pop();
      Node right = currentNode.right();
      if (right != null)
         nodes.push(right);
      Node left = currentNode.left();
      if (left != null)
         nodes.push(left);
      System.out.println("Node data: "+currentNode.data);
   }
}
