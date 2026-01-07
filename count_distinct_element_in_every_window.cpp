class Solution {
  public: //T.C: O(n) and S.C: O(n)
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        int left = 0;
        vector<int> ans;
        unordered_map<int,int>mpp;
        for(int right=0;right<n;right++){
            mpp[arr[right]]++;
            if(right-left+1>k){
                mpp[arr[left]]--;
                if(mpp[arr[left]]==0){
                    mpp.erase(arr[left]);
                }
                left++;
            }
            if(right-left+1==k){
                ans.push_back(mpp.size());
            }
            
        }
        return ans;
    }
};