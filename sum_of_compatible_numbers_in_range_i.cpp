class Solution {
public: //T.C: O(k) and S.C: O(1)
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for (int x = max(1, n - k); x <= n + k; x++) {
            if ((n & x) == 0) {
                ans += x;
            }
        }
        return ans;
    }
};