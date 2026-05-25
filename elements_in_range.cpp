class Solution {
  public: //T.C: O(n) and S.C: O(n)
    bool checkElements(int start, int end, vector<int> &arr) {
        unordered_set<int>st;
        for(int num : arr){
            st.insert(num);
        }
        
        for(int i=start;i<=end;i++){
            if(st.find(i)==st.end()){
                return false;
            }
        }
        return true;
    }
};
