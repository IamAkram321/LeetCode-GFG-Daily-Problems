class Solution {
  public:
    int countSetBits(int n) {
        int count = 0;
        for (long long i = 1; i <= n; i <<= 1) {  
            long long cycle = i << 1;
            count += (n / cycle) * i;
            long long rem = n % cycle;
            if (rem >= i) count += rem - i + 1;
        }
        return count;
    }
};
