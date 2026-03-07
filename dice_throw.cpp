class Solution {
  public:
    int dp[51][51];
    int solve(int m, int n, int x, int sum){
        int ways = 0;
        if(n==0) return (sum==x)?1:0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        for(int i=1;i<=m;i++){
            if(sum+i<=x){
                 ways+=solve(m,n-1,x,sum+i);
            }
        }
        return dp[n][sum] = ways;
    }
    int noOfWays(int m, int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,x,0);
    }
};