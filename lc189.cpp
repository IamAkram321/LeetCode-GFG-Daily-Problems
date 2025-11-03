class Solution {
public: //T.C: O(n) and S.C: O(n)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tempArray(n);

        for(int i=0;i<n;i++){
            tempArray[(i+k)%n] = nums[i];
        }

        nums = tempArray;
    }
};