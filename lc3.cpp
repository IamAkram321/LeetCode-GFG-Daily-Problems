class Solution {
public://T.C: O(n) and S.C:O(n)
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0, end = 0, maxLen = 0;
        unordered_set<char>st;
        while(end < n){
            if(st.find(s[end]) == st.end()){
                st.insert(s[end]);
                maxLen = max(maxLen,end-start+1);
                end++;
            }else{
                st.erase(s[start]);
                start++;
            }
        }
        return maxLen;
    }
};