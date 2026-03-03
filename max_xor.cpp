class Solution {
  public:
  //T.C: O(n) ans S.C: O(1)
    int maxSubarrayXOR(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        int curr_xor=0;
        
        for(int i=0;i<k;i++){
            curr_xor ^= arr[i];
        }
        
        int max_xor = curr_xor;
        
        for(int i=k;i<n;i++){
            curr_xor ^= arr[i-k];
            curr_xor ^= arr[i];
            max_xor = max(max_xor,curr_xor);
        }
        return max_xor;
    }
};

/*
Brute force: Time: O(n · k)
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int maxXor = 0;

        for (int i = 0; i + k <= n; i++) {
            int currXor = 0;
            for (int j = i; j < i + k; j++) {
                currXor ^= arr[j];
            }
            maxXor = max(maxXor, currXor);
        }
        return maxXor;
    }
};
*/