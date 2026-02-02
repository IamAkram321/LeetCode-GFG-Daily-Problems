class Solution {
public: //T.C: (n) and S.C: O(1)
    int maxCircularSum(vector<int>& arr) {
        int total_sum = 0;
        
        int max_sum = arr[0], curr_max = 0;
        int min_sum = arr[0], curr_min = 0;
        
        for(int x : arr){
            total_sum += x;
            curr_max = max(x, curr_max+x);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(x,curr_min+x);
            min_sum = min(min_sum, curr_min);
        }
        if(max_sum<0) return max_sum;
        return max(max_sum,total_sum-min_sum);
    }
};