class Solution {
public: //T.C: O(N) and S.C: O(N)
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();

        vector<int> right_max(n);
        right_max[n-1]=-1;
        int mx=nums[n-1];

        for(int i=n-2;i>=0;i--){
            right_max[i]=mx;
            mx=max(mx,nums[i]);
        }
        vector<int> ans;
        int left_max=nums[0];

        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                ans.push_back(nums[i]);
            }else if(nums[i]>left_max || nums[i]>right_max[i]){
                ans.push_back(nums[i]);
            }
            left_max = max(left_max,nums[i]);
        }
        return ans;
    }
}; 