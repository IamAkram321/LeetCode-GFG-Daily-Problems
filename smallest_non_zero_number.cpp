class Solution {
  public: //T.C: O(N) and S.C: O(1)
    int find(vector<int>& arr) {
        int required = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            required = (arr[i] + required + 1) / 2;
        }
        return max(1, required);
    }
};