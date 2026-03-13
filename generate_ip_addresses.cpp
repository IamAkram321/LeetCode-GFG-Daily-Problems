class Solution {
  public: //T.C: O(27 * n) and S.C: O(n)
    bool isValid(string s){
        if(s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    void solve(int idx, int parts, string &s, string curr, vector<string> &ans){
        if(parts == 4 && idx == s.size()){
            curr.pop_back(); 
            ans.push_back(curr);
            return;
        }
        if(parts >= 4) return;
        for(int len = 1; len <= 3; len++){
            if(idx + len > s.size()) break;
            string segment = s.substr(idx, len);
            if(isValid(segment)){
                solve(idx + len, parts + 1, s, curr + segment + ".", ans);
            }
        }
    }
    vector<string> generateIp(string &s) {
        vector<string> ans;
        if(s.size() < 4 || s.size() > 12) return ans;
        solve(0, 0, s, "", ans);
        return ans;
    }
};