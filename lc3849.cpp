class Solution {
public: //T.C: O(n) and S.C: O(1)
    string maximumXor(string s, string t) {
        int n = s.size();
        int zero = 0, one = 0;
        for(char c : t){
            if(c == '0') zero++;
            else one++;
        }
        string result = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(one > 0){
                    result += '1';
                    one--;
                } else {
                    result += '0';
                    zero--;
                }
            }
            else{ // s[i] == '1'
                if(zero > 0){
                    result += '1';
                    zero--;
                } else {
                    result += '0';
                    one--;
                }
            }
        }
        return result;
    }
};