class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();
        
        for(int p=1;p<n-2;p++){
            for(int q=p+1;q<n-1;q++){
                bool increasing = true;
                for(int i=1;i<=p;i++){
                    if(nums[i]<=nums[i-1]){
                        increasing = false;
                        break;
                    }
                }
                bool decreasing = true;
                for(int i=p+1;i<=q;i++){
                    if(nums[i]>=nums[i-1]){
                        decreasing = false;
                        break;
                    }
                }
                bool increasingLast = true;
                for(int i=q+1;i<n;i++){
                    if(nums[i]<=nums[i-1]){
                        increasing = false;
                        break;
                    }
                }
                if(increasing && decreasing && increasingLast) return true;
            }
        }
        return false;
    }
};