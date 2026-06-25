class Solution {
  public:
    void solve(int start, int n, string curr, vector<int>& ans) {
        if(curr.size() == n) {
            ans.push_back(stoi(curr));
            return;
        }
        for(int d = start; d <= 9; d++) {
            solve(d + 1, n, curr + char('0' + d), ans);
        }
    }
    vector<int> increasingNumbers(int n) {
       
       vector<int> ans;
        
        if(n == 1) {
            for(int i = 0; i <= 9; i++){
                 ans.push_back(i);
            }
            return ans;
        }
        if(n > 10) return ans;
        for(int first = 1; first <= 9; first++) {
            solve(first + 1, n, string(1, char('0' + first)), ans);
        }
        return ans;
       
    }
};