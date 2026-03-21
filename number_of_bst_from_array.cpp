class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        vector<int> catalan(n + 1, 0);
        catalan[0] = catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        unordered_map<int, int> bstCount;
        for (int i = 0; i < n; i++) {
            int left = i;           
            int right = n - i - 1;  
            bstCount[sortedArr[i]] = catalan[left] * catalan[right];
        }
        vector<int> result;
        for (int x : arr) result.push_back(bstCount[x]);
        return result;
    }
};
