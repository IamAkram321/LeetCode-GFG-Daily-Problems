class Solution {
public: //T.C : O(n) and S.C: O(k) or O(n) in worst case
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long curr_sum = 0, max_sum = 0;
        unordered_map<int,int> mpp;
        int left = 0;
        for(int right=0;right<n;right++){
            curr_sum += nums[right];
            mpp[nums[right]]++;
            
            //shrinking if duplicates elements are found

            while(mpp[nums[right]]>1){
                mpp[nums[left]]--;
                curr_sum -= nums[left];
                left++;
            }

            //shrinking if window size is greater than k
            while(right-left+1>k){
                mpp[nums[left]]--;
                curr_sum -= nums[left];
                left++;
            }

            if(right-left+1 == k){
                max_sum = max(max_sum,curr_sum);
            }
        }
        return max_sum;
    }
};