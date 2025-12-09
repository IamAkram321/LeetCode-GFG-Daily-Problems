class Solution {
public: //T.C: O(N) and S.C:(N)
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9+7;

        unordered_map<int,int> right;
        for(int x : nums) right[x]++;

        unordered_map<int,int> left;

        int ans = 0;

        for(int j=0;j<nums.size();j++){
            right[nums[j]]--;
            int target = nums[j]*2;

            ans = (ans + 1LL * left[target] * right[target])%MOD;

            left[nums[j]]++;
        }
        return ans;
        
    }
};