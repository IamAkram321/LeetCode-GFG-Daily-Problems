class Solution {
public:
    int countStrings(int n) {
        long long ending0 = 1; 
        long long ending1 = 1; 
        for (int i = 2; i <= n; i++) {
            long long new0 = ending0 + ending1;
            long long new1 = ending0;
            ending0 = new0;
            ending1 = new1;
        }
        return ending0 + ending1;
    }
};