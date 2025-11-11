class Solution {
public: //T.C: O(n) and S.C: O(1)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int i = 2; //to place next number
        for(int j=2;j<n;j++){
            if(nums[j] != nums[i-2]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};