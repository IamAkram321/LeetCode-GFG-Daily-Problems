class Solution {
  public: //T.C: O(n)
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
       unordered_set<int>uniqueElements;
       for(int num:a){
           uniqueElements.insert(num);
       }
       for(int num:b){
           uniqueElements.insert(num);
       }
       vector<int> ans;
       for(auto it : uniqueElements){
           ans.push_back(it);
       }
       
       return ans;
        
    }
};