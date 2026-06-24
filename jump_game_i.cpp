class Solution {
public: //T.C: O(n) and S.C:O(1)
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int to_reach=n-1;

        for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=to_reach){
                to_reach=i;
            }
        }
        return to_reach==0;
    }
};