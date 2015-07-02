// http://www.fusu.us/2013/06/p6-shortest-path-in-binary-tree.html
 void shortestpath(Node root, Node a, Stack<Node> outputPath) {
    if (root == null)
        return;

    if (root == a) {
        outputPath.push(root);
        return;
    }

    shortestpath(root.left, a, outputPath);
    shortestpath(root.right, a, outputPath);
    outputPath.push(root);
}

List<Node> shortestPath(Node root, Node a, Node b) {
    Stack<Node> path1 = new Stack();
    Stack<Node> path2 = new Stack();
    Node lca = lowestCommonAncestor(root, a, b);

    // This is to handle the case where one of the nodes IS the LCA
    Node r = lca.equals(a) ? a : (lca.equals(b) ? b : lca);

    shortestpath(r.left, a, path1);
    shortestpath(r.right, a, path2);
    path1.push(r);

    // invert the second path
    while (!path2.isEmpty()) {
        path1.push(path2.pop());
    }
    return path1;
}
