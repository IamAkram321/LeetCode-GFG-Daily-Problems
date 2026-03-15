/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, vector<int>> nodes;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int vertical = it.second;
            nodes[vertical].push_back(node->data);
            if(node->left){
                q.push({node->left, vertical-1});
            }
            if(node->right){
                q.push({node->right, vertical+1});
            }
        }
        
        vector<vector<int>> ans;
        for(auto p : nodes){
            ans.push_back(p.second);
        }
        return ans;
    }
};