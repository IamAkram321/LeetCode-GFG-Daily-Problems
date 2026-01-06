/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: //T.C: O(n) and S.C: O(n) in worst case : queue can hold up to O(n) nodes in the worst case
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int max_sum=INT_MIN;

        int curr_level = 1;
        int max_level =1;

        while(!q.empty()){
            int level_size = q.size();
            int level_sum = 0;
            for(int i=0;i<level_size;i++){
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level_sum>max_sum){
                max_sum = level_sum;
                max_level = curr_level;
            }
            curr_level++;
        }
        return max_level;
    }
};