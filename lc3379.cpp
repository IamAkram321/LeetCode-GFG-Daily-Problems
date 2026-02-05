class Solution {
public: //T.C: O(n) and S.C: O(n) for ans
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                result[i] = nums[i];
            }else{
                int newIndex = (i+nums[i]%n+n)%n;
                result[i] = nums[newIndex];
            }
        }
        return result;
    }
};