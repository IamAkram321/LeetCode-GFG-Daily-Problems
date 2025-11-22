class Solution {
public: //T.C: O(n) and S.C: O(1)
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%3 != 0) count++;
        }
        return count;
    }
};