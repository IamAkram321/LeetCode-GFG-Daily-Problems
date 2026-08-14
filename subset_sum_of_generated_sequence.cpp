class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        if (x == 0) return true;

        long long total = s;
        vector<long long> seq;

        if (s <= x) seq.push_back(s);
        for (int a : arr) {
            long long newValue = total + a;

            if (newValue > x) break;
            seq.push_back(newValue);
            total += newValue;
        }
        long long remaining = x;
        for (int i = seq.size() - 1; i >= 0; i--) {
            if (seq[i] <= remaining)
                remaining -= seq[i];

            if (remaining == 0)
                return true;
        }

        return false;
    }
};