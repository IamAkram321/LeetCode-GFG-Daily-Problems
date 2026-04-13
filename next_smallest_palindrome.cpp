class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        bool all9 = true;
        for (int d : num) {
            if (d != 9) {
                all9 = false;
                break;
            }
        }
        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = res[n] = 1;
            return res;
        }
        vector<int> pal = num;
        for (int i = 0; i < n / 2; i++) {
            pal[n - i - 1] = pal[i];
        }
        if (pal > num) return pal;
        int carry = 1;
        int mid = n / 2;
        if (n % 2 == 1) {
            pal[mid] += 1;
            carry = pal[mid] / 10;
            pal[mid] %= 10;
            mid--;
        } else {
            mid = mid - 1;
        }
        while (mid >= 0 && carry) {
            pal[mid] += carry;
            carry = pal[mid] / 10;
            pal[mid] %= 10;
            mid--;
        }
        for (int i = 0; i < n / 2; i++) {
            pal[n - i - 1] = pal[i];
        }
        return pal;
    }
};