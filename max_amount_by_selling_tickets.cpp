class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxAmount(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for (int x : arr) {
            pq.push(x);              //4,3,6,2,4 and k=3
        }
        long long sum = 0;
        while (k > 0 && !pq.empty()) {
            int curr = pq.top();
            pq.pop();
            sum = (sum + curr) % MOD;
            if (curr - 1 > 0) {
                pq.push(curr - 1);
            }
            k--;
        }
        return sum;
    }
};