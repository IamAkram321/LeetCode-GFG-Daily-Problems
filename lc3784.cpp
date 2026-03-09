class Solution {
public: //T.C: O(n) and S.C:O(26)
    long long minCost(string s, vector<int>& costs) {
        vector<long long> freq(26,0);
        long long total_cost = 0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a'] += costs[i];
            total_cost += costs[i];
        }
        return total_cost-*max_element(freq.begin(),freq.end());
    }
};
//instead of deleting , keep the max cost character and delete with total cost