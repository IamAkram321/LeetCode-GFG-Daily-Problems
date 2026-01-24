class Solution {
public: //T.C: O(n) and S.C: O(n)
    int findTheWinner(int n, int k) {
        // if(n==1) return 1;
        // return (findTheWinner(n - 1, k) + k - 1) % n + 1;


        //T.C: O(n) and S.C: O(1)

        int res = 1;
        for(int i=2;i<=n;i++){
            res = (res+k-1)%i+1;
        }
        return res;
    }
};