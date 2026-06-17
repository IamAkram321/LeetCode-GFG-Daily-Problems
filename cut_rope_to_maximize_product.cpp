class Solution {
public:
    int maxProduct(int n) {

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int len = 2; len <= n; len++) {
            for (int cut = 1; cut < len; cut++) {
                dp[len] = max(
                    dp[len],
                    max(cut * (len - cut),cut * dp[len - cut])
                );
            }
        }
        return dp[n];
    }
};