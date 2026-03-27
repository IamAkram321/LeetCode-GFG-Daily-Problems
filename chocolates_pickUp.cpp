class Solution {
  public:
    //T.C: O(n × m²) and S.C: O(n × m²)
    int n, m;
    int dp[71][71][71];
    
    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e9;
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = 0;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int curr;
                if (j1 == j2){
                    curr = grid[i][j1];
                }else{
                    curr = grid[i][j1] + grid[i][j2];
                }
                curr += solve(i + 1, j1 + d1, j2 + d2, grid);
                maxi = max(maxi, curr);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m - 1, grid);
    }
};