/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int kPathSum(Node* root, int k,int currSum,unordered_map<int,int> &prefixSum){
        if(!root) return 0;
        currSum+=root->data;
        int count = prefixSum[currSum-k];
        prefixSum[currSum]++;
        count+=kPathSum(root->left,k,currSum,prefixSum);
        count+=kPathSum(root->right,k,currSum,prefixSum);
        prefixSum[currSum]--;   
        return count;
    }
    int countAllPaths(Node *root, int k) {
        unordered_map<int,int> prefixSum;
        prefixSum[0]=1;
        return kPathSum(root,k,0,prefixSum);
    }
};
