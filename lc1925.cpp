class Solution {
public: //T.C: O(N*N) and S.C: O(1)
    int countTriples(int n) {
        int count = 0;

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c_sq = a * a + b * b;

                int c = (int) sqrt(c_sq);

                if (c * c == c_sq && c <= n) {
                    count++;
                }
            }
        }
        
        return count;
    }
};