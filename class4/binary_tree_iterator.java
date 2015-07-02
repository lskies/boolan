ublic class BinaryTreeIterator {
    private boolean isDone;
    private Queue<Node> queue= new LinkedList<Node> ();

    BinaryTreeIterator(Node node) {
        if (node.left != null) {
            queue.add(node.left);
        }
        if (node.right != null) {
            queue.add(node.right);
        }
        if (queue.size() < 1) {
            isDone = true;
        }
    }

    public boolean hasNext() {
        return !isDone;
    }

    public Node next() {
        if (isDone) {
            return null;
        }
        return getNextNode();
    }

    private Node getNextNode() {
        if (!queue.isEmpty()) {
            Node node = queue.remove();

            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }

            return node;
        }
        isDone = true;
        return null;
    }
}

