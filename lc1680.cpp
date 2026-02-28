class Solution {
public:
//T.C: O(nlogn)
    string decimalToBinary(int x){
        string binary = "";
        while(x){
            binary.push_back((x % 2) + '0');
            x /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        string result = "";
        for(int i=1;i<=n;i++){
            result += decimalToBinary(i);
        }
        long long decimal_value = 0;
        for(char c : result){
            decimal_value = (decimal_value*2 + (c-'0')) % MOD;
        }
        return decimal_value;
    }
};