class Solution {
public: //T.C: O(N*M) and S.C: O(N*M)
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        int total_elements=n*m;
        k=k%total_elements;
        vector<vector<int>> temp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int flat_index=i*m+j;
                int new_flat_index=(flat_index+k)%total_elements;
                int new_row=new_flat_index/m;
                int new_col=new_flat_index%m;
                temp[new_row][new_col]=grid[i][j];
            }
        }
        return temp;
    }
};
