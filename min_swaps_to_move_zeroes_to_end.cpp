class Solution {
public: //T.C: O(n) and S.C: O(1)
    int minimumSwaps(vector<int>& nums) {
        int zero_count=0;
        for(int num : nums){
            if(num == 0) zero_count++;
        }
        int count=0;
        for(int i=nums.size()-zero_count;i<nums.size();i++){
            if(nums[i] != 0){
                count++;
            }
        }
        return count;
    }
};