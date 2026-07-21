class Solution {
  public:
    int maxIndexDifference(string &s) {
        
        int n = s.size();

        vector<int> dp(n);
        vector<int> best(26, -1);

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            int ch = s[i] - 'a';
            if (ch == 25) {
                dp[i] = i;
            } else {
                if (best[ch + 1] != -1) dp[i] = best[ch + 1];
                else dp[i] = i;
            }
            best[ch] = max(best[ch], dp[i]);
            if (ch == 0) ans = max(ans, dp[i] - i);
        }
        return ans;
    }
};
