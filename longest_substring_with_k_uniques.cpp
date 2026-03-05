class Solution {
  public: //T.C: O(N) and S.C: O(K)
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int maxLen = -1;
        int left = 0;
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            while(mpp.size()>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            if(mpp.size()==k){
                maxLen = max(maxLen,right-left+1);
            }
        }
        return maxLen;
    }
};



class Solution {
  public: //T.C: O(N*N) and S.C:O(N)
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int maxLen = -1;
        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                if(st.size()>k){
                    break;
                }
                if(st.size()==k){
                    maxLen = max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
    }
};