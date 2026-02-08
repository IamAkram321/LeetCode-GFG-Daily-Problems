class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        //T.C: O(n*n) and S.C: O(1)
        // int n = nums.length;
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     long product = 1;
        //     for(int j=i;j<n;j++){
        //         product *= nums[j];
        //         if(product < k) count++;
        //     }
        // }
        // return count;


        //T.C: O(n) and S.C: O(1)

        if(k<=1) return 0;

        int count = 0;
        int product = 1;
        int left = 0;

        for(int right=0;right<nums.length;right++){
            product *= nums[right];
            while(product >= k){
                product/=nums[left];
                left++;
            }
            count += (right-left+1);
        }
        return count;
    }
}