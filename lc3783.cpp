class Solution {
public: //T.C: O(n) and S.C: O(1)
    int solve(int n){
        int rev = 0;
        while(n){
            int digit = n%10;
            rev = rev*10+digit;
            n/=10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        return abs(n-solve(n));
    }
};