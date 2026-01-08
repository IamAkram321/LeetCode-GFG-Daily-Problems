class Solution {
  public: //T.C: O(n) and S.C: O(n)
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        
        mpp[0]=1;
        int count = 0,sum=0;
        for(int num : arr){
            sum += num%2;
            if(mpp.count(sum-k)){
                count += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return count;
    }
};