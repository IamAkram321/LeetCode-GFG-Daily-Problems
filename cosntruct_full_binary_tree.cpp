/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    unordered_map<int, int> mp;

    Node* build(vector<int>& pre, vector<int>& preMirror,
                int preL, int preR,
                int mirL, int mirR) {
        if (preL > preR) return nullptr;

        Node* root = new Node(pre[preL]);
        if (preL == preR) return root;
        int leftRoot = pre[preL + 1];
        int idx = mp[leftRoot];  
        int rightSize = idx - mirL - 1;
        int leftSize  = (preR - preL) - rightSize;
        root->left = build(pre, preMirror,
                           preL + 1,
                           preL + leftSize,
                           idx,
                           mirR);
        root->right = build(pre, preMirror,
                            preL + leftSize + 1,
                            preR,
                            mirL + 1,
                            idx - 1);

        return root;
    }

    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        mp.clear();
        for (int i = 0; i < (int)preMirror.size(); ++i)
            mp[preMirror[i]] = i;

        return build(pre, preMirror,
                     0, (int)pre.size() - 1,
                     0, (int)preMirror.size() - 1);
    }
};