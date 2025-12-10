class Solution {
public: //T.C: O(N) and S.C: O(1)-->ignore ans vector
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i=0;
        int j=n;
        while(i<n && j<2*n){
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }
        return ans;
    }
};