/*
Definition for Node
class Node {
    int data;
    Node left;
    Node right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/
class Solution {
    String preOrder(Node node){
        if(node==null) return "null";
        StringBuilder sb = new StringBuilder("^");
        sb.append(node.data);
        sb.append(preOrder(node.left));
        sb.append(preOrder(node.right));
        return sb.toString();
    }
    public boolean isSubTree(Node root1, Node root2) {
       String fullTree=preOrder(root1);
       String subTree=preOrder(root2);
       return fullTree.contains(subTree);
    }
}