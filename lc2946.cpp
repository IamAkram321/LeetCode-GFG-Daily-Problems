class Solution {
public: //T.C: O(n*m) and S.C: O(1)
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k=k%m; //reducing k  

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2==0){ //even case
                    if(mat[i][j] != mat[i][(j+k)%m]){
                        return false;
                    }
                }else{
                    if(mat[i][j] != mat[i][(j-k+m)%m]){ //odd case
                        return false;
                    }
                }
            }
        }
        return true;
    }
};