class Solution {
  public: //T.C: O(n) and S.C: O(n)
    bool checkRedundancy(string &s) {
         stack<char> st;

        for (char ch : s) {
            if (ch != ')') {
                st.push(ch);
            } 
            else {
                bool hasOperator = false;
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();

                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }
                st.pop();
                if (!hasOperator) {
                    return true;
                }
            }
        }
        return false;
        
    }
};
