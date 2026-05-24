class Solution {
  public: //T.C: O(n) and S.C:O(1)
    int coin(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]>arr[j]){
                i++;
            }else{
                j--;
            }
        }
        return arr[j];
    }
};