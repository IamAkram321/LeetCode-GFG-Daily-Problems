class Solution {
public: //T.C : O(n) and S.C: O(1)
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= (start + 2*i);
        }
        return ans;
    }
};
