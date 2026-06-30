class MinStack {
public: //every operation is O(1) time
    int mini;
    stack<int>st;
    MinStack() {
        
    }
    void push(int val) {
        if(st.empty()) mini=val;
        else if(val<=mini){
           st.push(mini);
           mini=val;
        } 
        st.push(val);
    }
    
    void pop() {
        if(st.empty()) return;
        int top = st.top();
        st.pop();
        if(top==mini && !st.empty()){
            mini=st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};
