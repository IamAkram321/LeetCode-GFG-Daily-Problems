class Solution {
  public: //T.C: O(n) and S.C: O(1)
    string firstNonRepeating(string &s) {
        string result = "";
        unordered_map<char, int> freq; 
        queue<char> q; 
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch]++;
            q.push(ch);
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
            if (q.empty()) {
                result += '#';
            } else {
                result += q.front();
            }
        }
        
        return result;
    }
};