/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    struct Info {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };
    
    Info solve(Node* root, int &ans) {
        // Base case
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }
        
        // Leaf node
        if (!root->left && !root->right) {
            ans = max(ans, 1);
            return {true, 1, root->data, root->data};
        }
        
        Info left = solve(root->left, ans);
        Info right = solve(root->right, ans);
        
        Info curr;
        
        // Check BST condition
        if (left.isBST && right.isBST && 
            root->data > left.maxVal && root->data < right.minVal) {
            
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            
            ans = max(ans, curr.size);
        } else {
            curr.isBST = false;
            curr.size = max(left.size, right.size);
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};