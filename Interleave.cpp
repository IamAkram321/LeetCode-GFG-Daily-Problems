class Solution {
  public: //T.C: O(n) and S.C: O(2N)
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size(); 
        vector<int> firstHalf, secondHalf;
        
        for(int i=0;i<n/2;i++){
            firstHalf.push_back(q.front());
            q.pop();
        }
        for(int i=0;i<n/2;i++){
            secondHalf.push_back(q.front());
            q.pop();
        }
        for(int i=0;i<n/2;i++){
            q.push(firstHalf[i]);
            q.push(secondHalf[i]);
            
        }
        
    }
};
/******************************************************* */

class Solution {
  public: //T.C: O(n) and S.C:O(n/2)
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        stack<int> st;

        //Push first half into stack
        for(int i = 0; i < n/2; i++) {
            st.push(q.front());
            q.pop();
        }

       //Push stack elements back to queue
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        //Move first half to back
        for(int i = 0; i < n/2; i++) {
            q.push(q.front());
            q.pop();
        }

        //Push first half into stack again
        for(int i = 0; i < n/2; i++) {
            st.push(q.front());
            q.pop();
        }

        //  Interleave
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
