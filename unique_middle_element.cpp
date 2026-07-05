class Solution {
public: //T.C: O(N) and S.C: O(1)
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid_elem=nums[nums.size()/2];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mid_elem){
                count++;
            }
        }
        return count==1;
    }
};