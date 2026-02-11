class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        
        int n = heights.size();
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
            v.push_back({heights[i], cost[i]});

        sort(v.begin(), v.end());

        int totalWeight = 0;
        for(auto &p : v) totalWeight += p.second;

        int currWeight = 0;
        int median = 0;

        for(auto &p : v) {
            currWeight += p.second;
            if(currWeight >= (totalWeight + 1) / 2) {
                median = p.first;
                break;
            }
        }

        int ans = 0;
        for(auto &p : v)
            ans += abs(p.first - median) * p.second;

        return ans;
    }
};
