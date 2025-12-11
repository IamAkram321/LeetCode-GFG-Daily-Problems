class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
          unordered_map<int, set<int>> row, col;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            row[x].insert(y);
            col[y].insert(x);
        }

        int count = 0;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            auto itLeft = row[x].lower_bound(y);
            bool hasLeft = (itLeft != row[x].begin());
            bool hasRight = (++itLeft != row[x].end());
            
            auto itUp = col[y].lower_bound(x);
            bool hasUp = (itUp != col[y].begin());
            bool hasDown = (++itUp != col[y].end());

            if (hasLeft && hasRight && hasUp && hasDown) {
                count++;
            }
        }

        return count;
    }
};