class Solution {
  public: //T.C: O(n) and S.C: O(1)
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int max_sum = 0;
        int curr_sum = 0;
        int left = 0;
        for(int right=0;right<n;right++){
            curr_sum+=arr[right];
            while(right-left+1>k){
                curr_sum -= arr[left];
                left++;
            }
            if(right-left+1==k){
                max_sum = max(max_sum,curr_sum);
            }
        }
        return max_sum;
    }
};