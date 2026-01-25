class Solution {
public: //T.C: O(n/2) and S.C: O(1)
    int findWays(int n) {
        if (n % 2 != 0) return 0;  
        int k = n / 2;
        long long res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * 2 * (2 * i - 1) / (i + 1);
        }
        return (int)res;
    }
};
