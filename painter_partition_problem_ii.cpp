class Solution {
  public:

    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        long long currTime = 0;
        int painters = 1;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > maxTime) return false;

            if(currTime + arr[i] <= maxTime) {
                currTime += arr[i];
            } 
            else {
                painters++;
                currTime = arr[i];
            }
        }

        return painters <= k;
    }

    int minTime(vector<int>& arr, int k) {
        
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;

        for(int x : arr) high += x;

        long long ans = high;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
