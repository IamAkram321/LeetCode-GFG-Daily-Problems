class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        long long total = 0;
        
        for(int x : arr) total += x;
        
        // If total sum is odd, cannot split equally
        if(total % 2 != 0) return false;
        
        long long prefix = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            prefix += arr[i];
            
            if(prefix == total / 2) {
                return true;
            }
        }
        
        return false;
    }
};