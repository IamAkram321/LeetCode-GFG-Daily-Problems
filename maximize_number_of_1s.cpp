class Solution {
  public: //T.C: O(N) and S.C:O(1)
    int maxOnes(vector<int>& arr, int k) {
        
        int i=0,j=0;
        int n = arr.size();
        int maxLen = 0;
        int zeroCount = 0;
        while(j<n){
            if(arr[j]==0){
                zeroCount++;
            }
            while(zeroCount > k){
                if(arr[i]==0){
                    zeroCount--;
                }
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
