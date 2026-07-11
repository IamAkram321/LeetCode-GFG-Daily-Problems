class Solution {
public:
    int n, m;
    int ans = -1;
    
    void dfs(vector<vector<int>>& mat, int x, int y,
             int xd, int yd, int dist) {
        
        // Reached destination
        if (x == xd && y == yd) {
            ans = max(ans, dist);
            return;
        }
        
        // Mark current cell as visited
        mat[x][y] = 0;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                mat[nx][ny] == 1) {
                
                dfs(mat, nx, ny, xd, yd, dist + 1);
            }
        }
        
        // Backtrack: make the cell available again
        mat[x][y] = 1;
    }
    
    int longestPath(vector<vector<int>>& mat, int xs, int ys,
                    int xd, int yd) {
        
        n = mat.size();
        m = mat[0].size();
        
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;
        
        dfs(mat, xs, ys, xd, yd, 0);
        
        return ans;
    }
};