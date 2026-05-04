class Solution {
  public: //T.C: OO(log n) and S.C: O(log n)
    bool checkPalindrome(string bin){
        int i=0,j=bin.size()-1;
        while(i<=j){
            if(bin[i]!=bin[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isBinaryPalindrome(int n) {
       string bin="";
       while(n){
           int bit = n%2;
      	   bin.push_back('0' + bit);
           n /= 2;
       }
       reverse(bin.begin(),bin.end());
       bool result = checkPalindrome(bin);
       if(result) return true;
       else return false;
    }
};