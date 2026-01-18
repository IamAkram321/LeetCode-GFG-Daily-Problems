class Solution {
  public: //T.C: O(n) and S.C: O(n)
    vector<int> nextFreqGreater(vector<int>& arr) {
       unordered_map<int,int>freq;
       
       for(int num : arr) freq[num]++;
       
       stack<int> st;
       
       vector<int> ans(arr.size(),-1);
       
       for(int i=arr.size()-1;i>=0;i--){
           int curr = arr[i];
           while(!st.empty() && freq[st.top()] <= freq[curr]){
               st.pop();
           }
           if(!st.empty()){
               ans[i] = st.top();
           }
           st.push(curr);
       }
       return ans;
       
    }
};
