class Solution {
public: //T.C: O(n) and S.C: O(k)
    int countAtMostK(vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;
        int left = 0;
        unordered_map<int,int> mpp;
        for(int right = 0;right<n;right++){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            count += (right-left+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMostK(nums,k)-countAtMostK(nums,k-1);
    }
};
/*

At most K counts everything up to K.
At most K−1 counts everything before K.
Subtracting leaves exactly K.

*/