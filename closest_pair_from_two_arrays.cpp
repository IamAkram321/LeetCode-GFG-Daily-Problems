class Solution {
  public: //T.C: O(n+m)
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int i = 0, j=arr2.size()-1;
        int minDiff = INT_MAX;
        vector<int> ans;
        while(i<arr1.size() && j>=0){
            int sum = arr1[i]+arr2[j];
            int diff = abs(sum-x);
            if(diff<minDiff){
                minDiff = diff;
                ans = {arr1[i],arr2[j]};
            }
            if(sum > x){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};