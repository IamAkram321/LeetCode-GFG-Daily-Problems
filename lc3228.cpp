class Solution {
public: //T.C: O(n) and S.C: O(1)
    int maxOperations(string s) {
       int zero_segments = 0;
       int count = 0;
       for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                if(i == s.size()-1 || s[i+1] == '1'){
                    zero_segments++;
                }
            }else{
                count += zero_segments;
            } 
       }
       return count;
    }
};