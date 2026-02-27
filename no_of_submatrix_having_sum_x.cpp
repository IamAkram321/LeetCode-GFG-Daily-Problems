class Solution {
  public: //T.C: O(nm)+O(nm⋅min(n,m))
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = mat[i][j];
                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int maxSize = min(n-i,m-j);
                for(int size=1; size<=maxSize; size++){
                    int r1=i;
                    int c1=j;
                    int r2=i+size-1;
                    int c2=j+size-1;
                    int sum = prefix[r2][c2];
                    if(r1>0) sum -= prefix[r1-1][c2];
                    if(c1>0) sum -= prefix[r2][c1-1];
                    if(r1>0 && c1>0) sum += prefix[r1-1][c1-1];

                    if(sum==x) count++;
                }
            }
        }

        return count;
    }
};