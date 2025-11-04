class Solution {
public: //T.C: O(N) and S.C: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mpp;
       for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(mpp.find(moreNeeded)!=mpp.end()){
                return {i,mpp[moreNeeded]};
            }
            mpp[num] = i;
       }
       return {};
    }
};