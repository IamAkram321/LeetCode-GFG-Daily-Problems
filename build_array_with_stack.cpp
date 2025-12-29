class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int i = 0; 
        
        for (int num = 1; num <= n && i < target.size(); num++) {
            ops.push_back("Push");
            
            if (num == target[i]) {
                i++;  
            } else {
                ops.push_back("Pop");  
            }
        }
        
        return ops;
    }
};
