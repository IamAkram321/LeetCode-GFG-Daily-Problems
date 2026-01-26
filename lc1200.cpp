class Solution {
public: //T.C: O(nlogn) and S.C: O(1) ignoring ans vector
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int mini = INT_MAX;
        for(int i=1;i<arr.size();i++){
            mini = min(mini, arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1] == mini){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        
        return ans;
    }
};