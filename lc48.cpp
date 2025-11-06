class Solution {
public: //T.C: O(n*n) ans S.C: O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //first we are transposing the matrix
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //second we are reversing each row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};