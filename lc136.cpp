class Solution {
public: //T.C: O(n) and S.C: O(1) Using XOR to find the single number when every other number appears exactly twice
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int num : nums){
            a ^= num;
        }
        return a;
    }
};