class Solution {
public: //T.C: O(N) and S.C:O(1)
    int countPermutations(vector<int>& complexity) {

        int ans = 1;
        const int MOD = 1e9+7;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i] <= complexity[0]) return 0;
            ans = (ans * 1LL * i)%MOD;
        }
        return ans;
    }
};