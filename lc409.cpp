class Solution {
public: //T.C: O(n) and S.C: O(1) ~ 52 characters only
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for(char c : s){
            mpp[c]++;
        }
        int length = 0;
        bool hasOdd = false;
        for(auto it : mpp){
            if(it.second%2==0){
                length += it.second;
            }
            else{
                length += it.second-1;
                hasOdd = true;
            }
        }
        if(hasOdd) length += 1;
        return length;
    }
};