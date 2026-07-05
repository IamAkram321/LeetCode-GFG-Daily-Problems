class Solution {
public://T.C: O(n) and S.C: O(1)--> only 26 characters we are storing
    int maxCharGap(string &s) {
        vector<int> freq(26,-1);
        int ans=-1;
        for(int i=0;i<s.size();i++){
            int idx = s[i]-'a';
            if(freq[idx]==-1){
                freq[idx]=i;
            }else{
                ans=max(ans,i-freq[idx]-1);
            }
        }
        return ans;
    }
};