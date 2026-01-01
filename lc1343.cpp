class Solution {
public: //T.C: O(n) and S.C: O(1)
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int left = 0, count = 0;

        int sum = 0;
        
        for(int right = 0; right<arr.size();right++){
            sum+=arr[right];
            while(right-left+1>=k){
                if(sum/k>=threshold) count++;
                sum -= arr[left++];
            }
        }
        return count;
        
    }
};

/*

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // Maintaining the window size of k
            if (i >= k) {
                sum -= arr[i - k];
            }

            // Checking condition when window size is exactly k
            if (i >= k - 1 && sum >= k * threshold) {
                count++;
            }
        }
        return count;
    }
};


*/