class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        long long reachable = 0;
        for(int x : arr) {
            if(x > reachable + 1){
                return reachable + 1;
            }
            reachable += x;
        }
        return reachable + 1;
    }
};