
class Solution {
  public: //T.C: O(rows × log(cols)) and S.C: O(1)
    int rowWithMax1s(vector<vector<int>> &arr) {
        
        int maxCount = -1;
        int row = -1;
        int rows = arr.size();
        int cols = arr[0].size();
        
        for(int i=0;i<rows;i++){
            int index = lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
            int ones = cols-index;
            if(ones > maxCount){
                maxCount = ones;
                row = i;
            }
        }
        return row;
        
    }
};