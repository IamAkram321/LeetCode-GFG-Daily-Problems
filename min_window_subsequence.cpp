class Solution {
  public: //T.C: O(S*T) and S.C: O(1)
    string minWindow(string& S, string& T) {
        string window = "";
        int j = 0;
        int minLen = S.length() + 1;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == T[j]) {
                j++;
                // Full T matched
                if (j == T.length()) {
                    int end = i + 1;
                    j--;
                    // Backward traversal to minimize window
                    while (j >= 0) {
                        if (S[i] == T[j]) j--;
                        i--;
                    }
                    j++;
                    i++;
                    if (end - i < minLen) {
                        minLen = end - i;
                        window = S.substr(i, minLen);
                    }
                }
            }
        }
        return window;
    }
};
