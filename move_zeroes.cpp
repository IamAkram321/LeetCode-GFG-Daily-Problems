class Solution {
  public: //T.C: O(n) and S.C: O(1)
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int nonZeroPosition = 0;
        for(int i=0;i<n;i++){
            if(arr[i] != 0){
                swap(arr[nonZeroPosition],arr[i]);
                nonZeroPosition++;
            }
        }
    }
};