class Solution {
public: //O(klogk) and S.C: O(k)
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        vector<int> rows, cols;

        rows.push_back(0);
        cols.push_back(0);

        for (auto &cell : arr) {
            rows.push_back(cell[0]);
            cols.push_back(cell[1]);
        }

        rows.push_back(n + 1);
        cols.push_back(m + 1);

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRowGap = 0;
        int maxColGap = 0;

        for (int i = 1; i < rows.size(); i++) {
            maxRowGap = max(maxRowGap, rows[i] - rows[i - 1] - 1);
        }

        for (int i = 1; i < cols.size(); i++) {
            maxColGap = max(maxColGap, cols[i] - cols[i - 1] - 1);
        }
        return maxRowGap * maxColGap;
    }
};