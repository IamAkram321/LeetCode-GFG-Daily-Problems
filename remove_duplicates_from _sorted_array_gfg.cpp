class Solution {
  public: //T.C: O(n) and S.C: O(1) excluding ans vector
    
    vector<int> removeDuplicates(vector<int> &arr) {
        
        int n = arr.size();
        vector<int> ans;
        
        
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i] != arr[i-1]){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};