class Solution {
public://T.C: O(n) and S.C: O(1)
    void moveZeroes(vector<int>& nums) {
        int nonZeroPosition = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                swap(nums[i],nums[nonZeroPosition]);
                nonZeroPosition++;
            }
        }
    }
};