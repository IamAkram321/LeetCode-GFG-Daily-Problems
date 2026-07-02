class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {

        vector<bool> dp(k, false);

        for (int x : arr) {
            vector<bool> next = dp;
            next[x % k] = true;
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    next[(r + x) % k] = true;
                }
            }
            dp = next;
            if (dp[0]) return true;
        }

        return false;
    }
};