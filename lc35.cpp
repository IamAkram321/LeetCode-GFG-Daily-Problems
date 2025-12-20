class Solution {
public: //T.C: O(logn) and S.C: O(1)
    int searchInsert(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == k) return mid;
            else if(nums[mid]<k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};