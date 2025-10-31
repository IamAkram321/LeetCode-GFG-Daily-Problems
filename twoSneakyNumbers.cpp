/*Leetcode: 3289
    T.C: O(N)
    S.C: O(1)
*/

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int num : nums){
            mpp[num]++;
        }
        vector<int> ans;
        for(const auto& it : mpp){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};