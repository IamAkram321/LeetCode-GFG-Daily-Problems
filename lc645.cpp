class Solution {
public: //T.C: O(N) and S.C:O(1)
    vector<int> findErrorNums(vector<int>& nums) {
        int repeating = -1, missing = -1;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if(nums[index]<0){
                repeating = abs(nums[i]);
            }else{
                nums[index] = -nums[index];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                missing = i+1;
            }
        }
        return {repeating,missing};
    }
};