class Solution {
  public:
    int minMen(vector<int>& arr) {
         int n = arr.size();
        vector<pair<int,int>> intervals;
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                intervals.push_back({L, R});
            }
        }
        sort(intervals.begin(), intervals.end());
        int workers = 0;
        int currEnd = 0;
        int i = 0;

        while (currEnd < n) {
            int maxReach = currEnd;

            while (i < intervals.size() && intervals[i].first <= currEnd) {
                maxReach = max(maxReach, intervals[i].second + 1);
                i++;
            }
            if (maxReach == currEnd)
                return -1;
            workers++;
            currEnd = maxReach;
        }
        return workers;
    }
};