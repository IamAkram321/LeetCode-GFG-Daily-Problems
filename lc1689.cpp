class Solution {
public: //T.C: O(N) and S.C: O(1)
    int minPartitions(string n) {
        int result = 0;
        for(char ch : n){
            result = max(result,ch-'0');
        }
        return result;
    }
};