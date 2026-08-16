class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        
        int minDist = INT_MAX;
        int index = -1;

        for (int i = 0; i < drones.size(); i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int r = drones[i][2];

            int distance = abs(x - target[0]) + abs(y - target[1]);
            if (distance <= r) {
                if (distance < minDist ||
                    (distance == minDist && i < index)) {
                    minDist = distance;
                    index = i;
                }
            }
        }
        return index;
    }
};