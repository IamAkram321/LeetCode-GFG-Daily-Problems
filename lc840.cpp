class Solution {
public: //T.C: O(row*col) and S.C: O(1)

    bool isMagic(vector<vector<int>>& g, int r, int c) {
    // Center must be 5
    if (g[r+1][c+1] != 5) return false;

    vector<bool> seen(10, false);

    // Check numbers 1–9 and uniqueness
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            int val = g[i][j];
            if (val < 1 || val > 9 || seen[val]){
                return false;
            }
            seen[val] = true;
        }
    }

    int sum = g[r][c] + g[r][c+1] + g[r][c+2];

    // Rows
    for (int i = 0; i < 3; i++)
        if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != sum){
            return false;
        }
            

    // Columns
    for (int j = 0; j < 3; j++)
        if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != sum){
             return false;
        }
           

    // Diagonals
    if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum){
        return false;
    }
        

    if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum){
        return false;
    }
        
    return true;
}

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < row; i++) {
            for (int j = 0; j + 2 < col; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};