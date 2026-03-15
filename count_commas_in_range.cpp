class Solution {
public: //T.C: O(1) and S.C:O(1)
    int countCommas(int n) {
        if(n < 1000) return 0;
        return n - 999;
    }
};