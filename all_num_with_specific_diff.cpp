class Solution {
public:
    //T.C: O(logn) and S.C: O(1)
    int find_sum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int getCount(int n, int d) {
        
        long long left = 0, right=n;
        long long ans = n+1;
        while(left<=right){
            long long mid = left+(right-left)/2;
            if(mid-find_sum(mid)>=d){
                ans = mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        if(ans==n+1) return 0;
        return n-ans+1;
    }
};
/*Brute Force: O(nlogn)*/

class Solution {
public:

    int find_sum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int getCount(int n, int d) {
        
        int count = 0;

        for(int i = 0; i <= n; i++){
            if(i - find_sum(i) >= d){
                count++;
            }
        }

        return count;
    }
};
