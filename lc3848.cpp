class Solution {
public://T.C: O(9!∗9)
   bool isDigitorialPermutation(int n) {
    static int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    string s = to_string(n);
    sort(s.begin(), s.end());
    do {
        if(s[0]=='0') continue;
        long long sum = 0;
        for(char c : s){
            sum += fact[c - '0'];
        }
        long long num = stoll(s);
        if(sum == num) return true;
    } while(next_permutation(s.begin(), s.end()));
        return false;
    }
};