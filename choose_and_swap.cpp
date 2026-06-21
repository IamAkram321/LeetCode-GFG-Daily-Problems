class Solution {
  public:
    string chooseSwap(string &s) {
        vector<int> last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> vis(26, false);
        for (int i = 0; i < s.size(); i++) {
            vis[s[i] - 'a'] = true;
            for (char ch = 'a'; ch < s[i]; ch++) {
                if (!vis[ch - 'a'] && last[ch - 'a'] > i) {
                    char a = s[i];
                    char b = ch;
                    for (char &c : s) {
                        if (c == a) c = b;
                        else if (c == b) c = a;
                    }
                    return s;
                }
            }
        }

        return s;
    }
};