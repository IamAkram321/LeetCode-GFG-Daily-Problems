class Solution {
public: //T.C: O(n) and S.C: O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int prefix_sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            prefix_sum += nums[i];
            int remove = prefix_sum-k;
            count += mpp[remove];
            mpp[prefix_sum]++;
        }
        return count;
    }
};