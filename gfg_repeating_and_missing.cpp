class Solution {
  public: //T.C: O(n) and S.c:O(1)
    vector<int> findTwoElement(vector<int>& arr) {
        int repeating  = -1, missing = -1;
        for(int i=0;i<arr.size();i++){
            int index = abs(arr[i])-1;
            if(arr[index] < 0){
                repeating = abs(arr[i]);
            }
            else{
                arr[index] = -arr[index];
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0){
                missing = i+1;
            }
        }
        return {repeating,missing};
    }
};