class Solution {
public: //T.C: O(n) and S.C : (1)
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int max_sum = 0;
        for(int i=0;i<=n-k;i++){
            int sum  = 0;
            for(int j=i;j<i+k;j++){
                sum += nums[j];
            }
            max_sum = max(max_sum, sum);
        }
        return (double) max_sum/k;
    }
};