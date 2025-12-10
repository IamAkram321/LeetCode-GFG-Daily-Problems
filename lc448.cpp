class Solution {
public: //T.C: O(N) and S.C:O(1)
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if(nums[index]>0){
                nums[index] = -nums[index];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};