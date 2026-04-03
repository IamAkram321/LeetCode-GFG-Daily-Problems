class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> ans;
        for (int s = 0; s <= 2 * n - 2; s++) {
            for (int i = 0; i < n; i++) {
                int j = s - i;
                if (j >= 0 && j < n) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};