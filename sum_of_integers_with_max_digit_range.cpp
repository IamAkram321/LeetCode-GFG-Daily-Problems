class Solution {
public: //T.C: O(N) and S.C: O(1)
    int find_max(int n){
        int ans=INT_MIN;
        while(n){
            ans=max(ans,n%10);
            n/=10;
        }
        return ans;
    }
    int find_mini(int n){
        int ans=INT_MAX;
        while(n){
            ans=min(ans,n%10);
            n/=10;
        }
        return ans;
    }
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int max_range=-1;
        for(int n : nums){
            max_range=max(max_range,find_max(n)-find_mini(n));
        }
        int sum=0;
        for(int num : nums){
            if(find_max(num)-find_mini(num) == max_range){
                sum += num;
            }
        }
        return sum;
    }
};