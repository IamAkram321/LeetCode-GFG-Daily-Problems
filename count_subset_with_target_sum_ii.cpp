class Solution {
  public: //T.C: O(2^(n/2) × log(2^(n/2))) and S.C: O(2^(n/2)), Meet in the Middle Algo
    
    void generateSubsets(vector<int>& arr, int start, int end, 
                         map<long long, int>& sumCount, long long sum) {
        if(start == end) {
            sumCount[sum]++;
            return;
        }
        generateSubsets(arr, start + 1, end, sumCount, sum + arr[start]);
        generateSubsets(arr, start + 1, end, sumCount, sum);
    }
    
    int countSubsets(vector<int>& arr, int start, int end, 
                     map<long long, int>& leftSums, long long k, long long sum) {
        if(start == end) {
           
            if(leftSums.find(k - sum) != leftSums.end()) {
                return leftSums[k - sum];
            }
            return 0;
        }
        int take = countSubsets(arr, start + 1, end, leftSums, k, sum + arr[start]);
       
        int notTake = countSubsets(arr, start + 1, end, leftSums, k, sum);
        
        return take + notTake;
    }
    
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        int mid = n / 2;
        map<long long, int> leftSums;
        generateSubsets(arr, 0, mid, leftSums, 0);
        return countSubsets(arr, mid, n, leftSums, k, 0);
    }
};