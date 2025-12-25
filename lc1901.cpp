class Solution {
public: //T.C: O(logn) and S.C: O(1)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int col = mat[0].size();

        int low = 0, high = col-1;

        while(low <= high){
            int midCol = low+(high-low)/2;
            int maxRow = 0;
            for(int i=0;i<rows;i++){
                if(mat[i][midCol] > mat[maxRow][midCol]){
                    maxRow = i;
                }
            }
            int left  = (midCol-1 >= 0)  ? mat[maxRow][midCol-1] : -1e9;
            int right = (midCol+1 < col) ? mat[maxRow][midCol+1] : -1e9;

            if(mat[maxRow][midCol] >= left && mat[maxRow][midCol]>= right){
                return {maxRow,midCol};
            }
            if(left > mat[maxRow][midCol]){
                high = midCol-1;
            }else{
                low  = midCol+1; 
            }
        }
        return {-1,-1};
    }
};