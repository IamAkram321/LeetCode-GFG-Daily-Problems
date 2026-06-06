class Solution {
  public:
    int numOfWays(int n, int m) {
        long long total = 1LL * n * m;
        long long ans = total * (total - 1);
        
        long long attacks = 0;
        attacks += 4LL * (n - 1) * (m - 2 > 0 ? m - 2 : 0);
        attacks += 4LL * (n - 2 > 0 ? n - 2 : 0) * (m - 1);
        
        return ans - attacks;
    }
};