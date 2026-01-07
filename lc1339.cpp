/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };what 
 */
class Solution {
public: //T.C: O(n) and S.C: O(h) where h is the hieght of binary tree
    long long total(TreeNode* root){
        if(!root) return 0;
        return total(root->left)+total(root->right)+root->val;
    }
    long long product_max(TreeNode* root, long long total_sum, long long& ans){
        if(!root) return 0;
        long long subtree_sum = 0;
        subtree_sum+=product_max(root->left,total_sum,ans);
        subtree_sum+=product_max(root->right,total_sum,ans);
        subtree_sum+=root->val;
        if((total_sum-subtree_sum)*subtree_sum > ans){
            ans = (total_sum-subtree_sum)*subtree_sum;
        }
        return subtree_sum;
    }
    int maxProduct(TreeNode* root) {
        long long total_sum = total(root);
        long long ans = 0;
        product_max(root,total_sum,ans);
        return ans%1000000007;
    }
};