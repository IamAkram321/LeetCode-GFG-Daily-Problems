class Solution {
public: //T.C: O(n) and S.C: O(n)--> ans 
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i=0,j=n-1;
        int idx = n-1;
        while(i<=j){
            int a = abs(nums[i]);
            int b = abs(nums[j]);
            if(b>a){
                ans[idx] = b*b;
                j--;
            }else{
                ans[idx] = a*a;
                i++;
            }
            idx--;
        }
        return ans;
    }
};