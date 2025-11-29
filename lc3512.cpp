class Solution {
public: //T.C: O(n+k)~O(n) and S.C:O(1)
    int minOperations(vector<int>& nums, int k) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k==0) return 0;
        int x = 1;
        while((sum - x)%k!=0){
            x++;
        } 
        return x;
    }
};