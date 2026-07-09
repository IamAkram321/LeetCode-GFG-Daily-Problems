class Solution {
  public: //Brute force : O(n*n) and S.C: O(1)
    int countKdivPairs(vector<int>& arr, int k) {
       
       int n=arr.size();
       int count=0;
    //   for(int i=0;i<n;i++){
    //       for(int j=i+1;j<n;j++){
    //           if((arr[i]+arr[j])%k==0){
    //               count++;
    //           }
    //       }
    //   }
    //   return count;
       
       
       //T.C: O(N) and S.C: O(N)
       unordered_map<int,int> mpp;
       
       for(int x : arr){
           int rem=x%k;
           int need=(k-rem)%k;
           count+=mpp[need];
           mpp[rem]++;
       }
       return count;
       
    }
};