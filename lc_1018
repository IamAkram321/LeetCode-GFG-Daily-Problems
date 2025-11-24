class Solution {
public: //T.C: O(n) and S.C: O(n)
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int current = 0;

        for(int bit : nums){
            current = (current * 2 + bit) % 5;
            ans.push_back(current == 0);
        }

        return ans;
    }
};
