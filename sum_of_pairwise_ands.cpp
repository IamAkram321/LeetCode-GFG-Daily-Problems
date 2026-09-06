class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {

        int n = arr.size();
        long long sum = 0;

        for(int bit = 0; bit < 32; bit++) {

            long long cnt = 0;

            for(int i = 0; i < n; i++) {
                if(arr[i] & (1LL << bit)) {
                    cnt++;
                }
            }
            long long pairs = cnt * (cnt - 1) / 2;
            sum += pairs * (1LL << bit);
        }

        return sum;
    }
};