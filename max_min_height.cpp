class Solution {
public:
    
    bool isPossible(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<long long> water(n + 1, 0); 
        long long currentWater = 0;
        long long usedWater = 0;

        for (int i = 0; i < n; ++i) {
            currentWater += water[i]; 
            long long height = arr[i] + currentWater;

            if (height < target) {
                long long needed = target - height;
                usedWater += needed;
                if (usedWater > k) return false; 

                currentWater += needed;
                if (i + w < n)
                    water[i + w] -= needed; 
            }
        }

        return true; 
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k; 
        int answer = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, w, mid)) {
                answer = mid;    
                low = mid + 1;
            } else {
                high = mid - 1;    
            }
        }

        return answer;
    }
};
