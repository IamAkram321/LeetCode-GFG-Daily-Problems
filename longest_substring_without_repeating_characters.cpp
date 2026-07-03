class Solution {
public: //T.C : O(n) and S.C: O(n)
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> st;

        int left=0, right=0, max_len=0;
        while(right<s.size()){
            if(st.find(s[right]) == st.end()){ //go until repeating character occurs
                st.insert(s[right]);
                max_len=max(max_len,right-left+1);
                right++;
            }else{
                st.erase(s[left++]);
            }
        }
        return max_len;
    }
};
