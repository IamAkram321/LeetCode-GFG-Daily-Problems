class Solution {
public: //O(N) and S.C: O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        while(i<j){
            if(nums[i]%2==0){
                i++;
            }else if(nums[j]%2!=0){
                j--;
            }else{
                swap(nums[i++],nums[j--]);
            }
        }
        return nums;
    }
};