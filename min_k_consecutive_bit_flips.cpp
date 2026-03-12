#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flips = 0;       
        int flipParity = 0;  
        queue<int> q;        

        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() == i) {
                q.pop();
                flipParity ^= 1;
            }
            if ((arr[i] ^ flipParity) == 0) {
                if (i + k > n) return -1;
                flips++;
                flipParity ^= 1;
                q.push(i + k); 
            }
        }

        return flips;
    }
};
