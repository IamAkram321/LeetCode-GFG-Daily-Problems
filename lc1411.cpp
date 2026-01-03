class Solution {
public:
    //T.C: O(n) and S.C: O(1)
    int numOfWays(int n) {
        const int mod=1e9+7;
        long long a=6; 
        long long b=6;
        for (int i=2;i<=n;i++) {
            long long A=(2*a+2*b)%mod; //here a and b represent the number of ways the previous row was Type A or Type B.
            long long B =(2*a+3*b)%mod;
            a=A;
            b=B;
        }
        return (a+b)%mod;
    }
};
/*
From any Type A row, we can form 2 Type A and 2 Type B rows.

From any Type B row, we can form 2 Type A and 3 Type B rows.
*/