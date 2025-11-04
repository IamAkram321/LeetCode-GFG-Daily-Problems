class Solution {
public: //T.C: O(n) and S.C: O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);
        left[0] = 1, right[n-1] = 1;
        
        for(int i=1;i<n;i++){
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
// ############################################################################################

class Solution {
public: //T.C: O(n) and S.C: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n,1);
        //prefix products calculation
        for(int i=1;i<n;i++){
            ans[i] = nums[i-1] * ans[i-1];
        }
        //suffix products calculation
        int suffix = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] *= suffix;
            suffix *= nums[i];
        }
       
        return ans;
    }
};