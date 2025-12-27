class Solution {
  public: //T.C: O(n × log(maxValue - minValue)) and S.C: O(1)
    int kthSmallest(vector<vector<int>> &mat, int k) {
        
        int n = mat.size();
        
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        
        while(low < high){
            int mid = low+(high-low)/2;
            int count = countLessEqaul(mat,mid);
            if(count < k){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    
    private:
        
        int countLessEqaul(vector<vector<int>> &mat, int mid){
            int n = mat.size();
            int i=n-1;
            int j=0;
            int count = 0;
            while(i>=0 && j<n){
                if(mat[i][j] <= mid){
                count += (i+1);
                    j++;
                }else{
                    i--;
                }
            }
            return count;
        }
};
