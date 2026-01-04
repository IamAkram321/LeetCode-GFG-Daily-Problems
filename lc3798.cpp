class Solution {
public://T.C: O(n) and S.C: O(1)
    string largestEven(string s) {
        int n = s.size();
        int idx = -1;
        for(int i=0;i<n;i++){
            if((s[i]-'0')%2==00){
                idx = i;
            }
        }
        if(idx==-1) return "";
        return s.substr(0,idx+1);
    }
};