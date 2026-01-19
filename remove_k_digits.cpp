class Solution {
  public: //T.C: O(3N)+ O(k) and S.C: O(2n)
    string removeKdig(string &s, int k) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()-'0'>s[i]-'0'){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string str = "";
        
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        int index = 0;
        while(index<str.size() && str[index]=='0') index++;
        str = str.substr(index);
        if(str.empty()) return "0";
        return str;
        
    }
};