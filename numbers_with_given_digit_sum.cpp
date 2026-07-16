class Solution {
  public: //T.C: O(n*sum) and S.C:O(n*sum)
    int solve(int pos, int n, int sum, vector<vector<int>> &dp){
        if(sum < 0) return 0;
        if(pos==n){
            return sum==0;
        }
        if(dp[pos][sum]!=-1){
            return dp[pos][sum];
        }
        int ways=0;
        int start=(pos==0)?1:0;
        for(int digit=start;digit<=9;digit++){
            ways+=solve(pos+1,n,sum-digit,dp);
        }
        return dp[pos][sum]=ways;
    }
    int countWays(int n, int sum) {
      
      vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
      int ans = solve(0,n,sum,dp);
      return ans==0?-1:ans;
      
    }
};