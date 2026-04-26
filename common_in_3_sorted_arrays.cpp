class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> ans;

        while (i < a.size() && j < b.size() && k < c.size()) {
            if (a[i] == b[j] && b[j] == c[k]) {
                ans.push_back(a[i]);
                int val = a[i];
                while (i < a.size() && a[i] == val) i++;
                while (j < b.size() && b[j] == val) j++;
                while (k < c.size() && c[k] == val) k++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else if (b[j] < c[k]) {
                j++;
            }
            else {
                k++;
            }
        }
        return ans;
    }
};