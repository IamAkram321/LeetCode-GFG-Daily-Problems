class Solution {
public: //T.C: O(N) and S.C:O(N)
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);
        vector<int> ans(nums.size());

        for(int x : nums){
            freq[x]++;
        }

        for(int i=1;i<=100;i++){
            freq[i] += freq[i-1];
        }

        for(int i=0;i<nums.size();i++){
            ans[i] = nums[i]==0?0:freq[nums[i]-1];
        }
        return ans;
    }
};