class Solution {
public: //T.C: O(k) where k is number of set bits and S.C:O(1)
    int hammingWeight(int n) {
        int count=0;
        while(n){
            n=n & (n - 1);
            count++;
        }
        return count;
    }
};