class Solution {
  public: //T.C: O(n) and S.C: O(1)
  
    int countAtMostK(string& s, int k) {
        if (k < 0) return 0;

        int n = s.size();
        int freq[26] = {0};
        int left = 0, distinct = 0;
        int count = 0;

        for (int right = 0; right < n; right++) {
            if (freq[s[right] - 'a']++ == 0) {
                distinct++;
            }
            while (distinct > k) {
                if (--freq[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    int countSubstr(string& s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};
