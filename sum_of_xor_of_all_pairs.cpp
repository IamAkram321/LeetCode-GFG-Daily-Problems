class Solution {
public: //T.C: O(32 * n) = O(n) and S.C:O(1)
    long long sumXOR(vector<int>& arr) {
        int n = arr.size();
        long long result = 0;
        for(int bit = 0; bit < 32; bit++) {
            long long ones = 0;
            for(int num : arr) {
                if(num & (1LL << bit)) ones++;   
            }
            long long zeros = n - ones;
            result += ones * zeros * (1LL << bit); 
        }
        return result;
    }
};