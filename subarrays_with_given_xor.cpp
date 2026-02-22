class Solution {
  public://T.C: O(n)
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int preXOR = 0, count=0;
        for(int i=0;i<arr.size();i++){
            preXOR^=arr[i];
            int remove = preXOR^k;
            count+=mpp[remove];
            mpp[preXOR]+=1;
        }
        return count;
    }
};
