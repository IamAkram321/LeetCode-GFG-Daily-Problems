class Solution {
public:
    long long solve(vector<int>& arr, int hour){
        long long totalHours = 0;
        for(int i = 0; i < arr.size(); i++){
            // Using integer math instead of ceil to prevent floating-point precision issues
            totalHours += (arr[i] + hour - 1) / hour;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalHours = solve(piles, mid);

            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)low;
    }
};