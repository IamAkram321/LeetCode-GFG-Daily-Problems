class Solution {
  public: //T.C: O(n) and S.C: O(k) or in worst case O(n)
    int longestKSubstr(string &s, int k) {
        
        int n = s.size();
        int max_length = -1;
        unordered_map<char,int> mpp;
        int left = 0;
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            
            //shrink if size if greater than k
            while(mpp.size()>k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            if(mpp.size() == k){
                max_length = max(max_length,right-left+1);
            }
            
        }
        return max_length;
    }
};