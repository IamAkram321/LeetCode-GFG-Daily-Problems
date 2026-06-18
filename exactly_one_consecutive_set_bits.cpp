class Solution {
public: //T.C: O(32) and S.C: O(1)
    bool consecutiveSetBits(int n) {
        if(n == 0) return false;
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));
        int pairs = 0;

        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == '1' && s[i+1] == '1') pairs++;
        }
        return pairs==1;
    } 
};