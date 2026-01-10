class Solution {
public: //T.C: O(n) and S.C: O(n)
    bool repeatedSubstringPattern(string s) {
       string temp = s+s;
       return temp.substr(1,temp.size()-2).find(s) != string::npos;
    }
};