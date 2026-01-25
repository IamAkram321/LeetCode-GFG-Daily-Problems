class Solution { //T.C: O(n log n) + O(n) = O(n log n) and S.C: O(1)
    public int minimumDifference(int[] nums, int k) {
        int n = nums.length;
        if (k == 1) return 0;

        Arrays.sort(nums);

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i <= n - k; i++) {
            ans = Math.min(ans,nums[i+k-1]-nums[i]);
        }
        return ans;
    }
}
