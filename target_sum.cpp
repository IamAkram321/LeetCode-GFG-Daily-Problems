class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int sum = 0;
        for (int x : arr) sum += x;
        if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;
        int s1 = (sum + target) / 2;
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;
        for (int num : arr) {
            for (int j = s1; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[s1];
    }
};