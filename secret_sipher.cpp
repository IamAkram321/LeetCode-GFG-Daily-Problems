class Solution {
public:
    string compress(string &s) {
        int n = s.size();
        vector<int> z(n);

        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        string ans;
        int k = 1;
        ans += s[0];
        while (k < n) {
            if (2 * k <= n && z[k] >= k) {
                ans += '*';
                k *= 2;
            } else {
                ans += s[k];
                k++;
            }
        }
        return ans;
    }
};