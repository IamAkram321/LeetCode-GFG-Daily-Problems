class Solution {
  public: //T.C: O(n^2) and S.C:O(n^2)
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<int> wife(n, -1), husband(n, -1), next(n, 0);
        vector<vector<int>> rank(n, vector<int>(n));
        
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        
        while (!q.empty()) {
            int m = q.front(); q.pop();
            
            int w = men[m][next[m]];
            next[m]++;
            
            if (husband[w] == -1) {
                husband[w] = m;
                wife[m] = w;
            } else {
                int m1 = husband[w];
                if (rank[w][m] < rank[w][m1]) {
                    husband[w] = m;
                    wife[m] = w;
                    wife[m1] = -1;
                    q.push(m1);
                } else {
                    q.push(m);
                }
            }
        }
        
        return wife;
    }
};