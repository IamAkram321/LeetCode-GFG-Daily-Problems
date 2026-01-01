class Solution {
  public: //T.C: O(n) and S.C: o(n)
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        int start = 0, end = 0, maxLen = 0;
        unordered_set<char> st;
        while(end<n){
            if(st.find(s[end]) == st.end()){
                st.insert(s[end]);
                maxLen = max(maxLen,end-start+1);
                end++;
            }else{
                st.erase(s[start++]);
            }
        }
        return maxLen;
    }
};
