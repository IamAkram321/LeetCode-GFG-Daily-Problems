class Solution {
    //T.C: O(n) and S.C: O(1)
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int i=0,j=n-1;
        int maxi = -1;
        while(i<j){
            int curr = nums[i]+nums[j];
            maxi = Math.max(curr,maxi);
            i++;
            j--;
        }
        return maxi;
    }
}