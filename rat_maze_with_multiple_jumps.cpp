class Solution {
  public:

    int dp[51][51];

    bool solve(int i, int j,
               vector<vector<int>>& mat,
               vector<vector<int>>& ans,
               int n)
    {
        if(i >= n || j >= n || mat[i][j] == 0) return false;
        if(i == n-1 && j == n-1)
        {
            ans[i][j] = 1;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        ans[i][j] = 1;
        int jump = mat[i][j];
        for(int step = 1; step <= jump; step++)
        {
            if(j + step < n &&
               solve(i, j + step, mat, ans, n))
            {
                return dp[i][j] = 1;
            }

            if(i + step < n &&
               solve(i + step, j, mat, ans, n))
            {
                return dp[i][j] = 1;
            }
        }

        ans[i][j] = 0;
        return dp[i][j] = 0;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat)
    {
        int n = mat.size();

        memset(dp, -1, sizeof(dp));
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if(solve(0, 0, mat, ans, n)) return ans;
        return {{-1}};
    }
};