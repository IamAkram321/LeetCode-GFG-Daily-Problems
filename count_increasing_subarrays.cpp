class Solution {
  public://T.C:O(N) and S.C:O(1)
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        int len=0;
        int count=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                len++;
                count+=len;
            }else{
                len=0;
            }
        }
        return count;
    }
};
