class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int prefixSum = 0, maxLength = 0;
        for(int i=0;i<arr.size();i++){
            prefixSum += arr[i] > k ? 1 : -1;
            if(prefixSum > 0) maxLength = i + 1;
            if(mpp.find(prefixSum -1) != mpp.end()){
                maxLength = max(maxLength, i - mpp[prefixSum-1]);
            }
            if(mpp.find(prefixSum) == mpp.end()){
                mpp[prefixSum] = i;
            }
        }
        return maxLength; 
    }
};

