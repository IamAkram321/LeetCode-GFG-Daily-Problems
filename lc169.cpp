class Solution {
public: // T.C: O(n) and S.C: O(1)
    //Moores's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int num;

        for(int i=0;i<n;i++){
            if(count == 0){
                count = 1;
                num = nums[i];
            }else if(nums[i] == num){
                count++;
            }else{
                count--;
            }
        }
        int total_count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == num) total_count++;
        }
        if(total_count > n/2) return num;
        return -1;
    }
};