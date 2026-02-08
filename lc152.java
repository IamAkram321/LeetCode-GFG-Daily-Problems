class Solution {
    //T.C: O(n) and S.C: O(1)
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int left_max  = Integer.MIN_VALUE;
        int right_max = Integer.MIN_VALUE;
        int left = 1, right = 1;
        for(int i=0;i<n;i++){
            left *= nums[i];
            left_max = Math.max(left,left_max);
            if(left == 0) left = 1;
        }
        for(int i=n-1;i>=0;i--){
            right *= nums[i];
            right_max = Math.max(right,right_max);
            if(right == 0) right = 1;
        }
        return Math.max(left_max, right_max);
    }
}