//Brute-force would be generating all the subarrays and checking each subarray if all the elements are zero
// or not. This give O(N^3) , if modified a little give O(N^2). Below is the optimal just by mainting streak. 
class Solution {
public: //T.C :O(n) and S.C: O(1)
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, length = 0;

        for(int num : nums){
            if(num == 0){
                length++;
                count += length;
            }else{
                length = 0;
            }
        }
        return count;
    }
};