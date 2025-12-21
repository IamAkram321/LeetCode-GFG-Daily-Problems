class Solution {
  public: //O(n + q log n) and S.C: O(n)
    vector<int> countXInRange(vector<int>& a, vector<vector<int>>& q) {

        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++) {
            pos[a[i]].push_back(i);
        }

        vector<int> ans;

        for (auto &query : q) {
            int l = query[0];
            int r = query[1];
            int x = query[2];

            if (pos.find(x) == pos.end()) {
                ans.push_back(0);
                continue;
            }

            auto &v = pos[x];

            int left = lower_bound(v.begin(), v.end(), l) - v.begin();
            int right = upper_bound(v.begin(), v.end(), r) - v.begin();

            ans.push_back(right - left);
        }

        return ans;
    }
};
