/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int moves = 0;
    int dfs(Node* root){
        if(root == nullptr) return 0;
        int leftReq  = dfs(root->left);
        int rightReq = dfs(root->right);
        moves += abs(leftReq) + abs(rightReq);
        return (root->data-1) + leftReq + rightReq;
    }
    int distCandy(Node* root) {
        
        dfs(root);
        return moves;
        
    }
};