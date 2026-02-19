class Solution {
public: //T.C: O(log n) 
    int mySqrt(int x) {
        long long low = 1, high=x, res;
        while(low <= high){
            long long mid = low+(high-low)/2;
            if(mid*mid==x){
                return mid;
            }else if(mid*mid<x){
                res = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
};