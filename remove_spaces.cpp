class Solution {
  public: //T.C: O(N) and S.C:O(N)
    string removeSpaces(string& s) {
        string str = "";
        for(char ch : s){
            if(ch!=' '){
                str+=ch;
            }
        }
        return str;
    }
};