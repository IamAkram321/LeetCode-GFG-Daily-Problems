class Solution {
  public: //T.C: O(nlogn) and S.C: O(n)
    void sortIt(vector<int>& arr) {
        
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        vector<int>temp(n);
        int index = 0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]%2==1){
                temp[index++] = arr[i];
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                temp[index++] = arr[i];
            }
        }
        arr = temp;
    }
};