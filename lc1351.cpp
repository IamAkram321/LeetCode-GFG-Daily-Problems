class Solution {
public: //T.C: O(n logm) and S.C: O(1)
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        // for(int i=0;i<n;i++){
        //     int low = 0, high = m-1;
        //     int firstNeg = m;
        //     while(low <= high){
        //         int mid = low + (high-low)/2;
        //         if(grid[i][mid]<0){
        //             firstNeg = mid;
        //             high = mid-1;
        //         }else{
        //             low = mid+1;
        //         }
        //     }
        //     count += (m-firstNeg);
        // }
        // return count;

        //Two Pointer Approach : T.C: O(n+m)

        int row = 0, col = m-1;
        while(row<n && col>=0){
            if(grid[row][col]<0){
                count += (n-row);
                col--;
            }else{
                row++;
            }
        }
        return count;
    }
};