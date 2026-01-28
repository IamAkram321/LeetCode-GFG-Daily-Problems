class Solution {
public: //T.C: O(N∗2^N) and S.C: O(N∗2^N)
    void recur_subset(int i,vector<int>& nums,vector<int> subset,vector<vector<int>>& result){
        if(i==nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        recur_subset(i+1,nums,subset,result);
        subset.pop_back();
        recur_subset(i+1,nums,subset,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        recur_subset(0,nums,subset,result);
        return result;
    }
};