class Solution {
public: //T.C: O(n) and S.C: O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int count = 0;
        int left=0,prod=1;
        for(int right=0;right<nums.size();right++){
            prod *= nums[right];
            while(prod >= k){
                prod/=nums[left];
                left++;
            }
            count += (right-left+1);
        }
        return count;
    }
};