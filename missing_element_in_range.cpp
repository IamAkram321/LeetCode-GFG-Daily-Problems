class Solution {
  public: //T.C: O(n+range)
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        
        // vector<int> ans;
        
        // unordered_set<int> st(arr.begin(),arr.end());
        
        // for(int i=low;i<=high;i++){
        //     if(st.find(i)==st.end()){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        
        //T.C: O(n log n + missing)
        sort(arr.begin(),arr.end());
        vector<int> ans;
        
        //gap before first element
        for(int i=low;i<arr[0];i++){
            ans.push_back(i);
        }
        //gap between elements;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=arr[i]+1;j<arr[i+1];j++){
                ans.push_back(j);
            }
        }
        //gap after last element
        
        for(int i=arr.back()+1;i<=high;i++){
            ans.push_back(i);
        }
        return ans;
        
    }
};