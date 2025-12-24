class Solution {
    public: //T.C: O(logn) and S.C: O(1)
    int countLessEqual(vector<int>& arr, int x) {
        
        int n = arr.size();
        int pivot = findPivot(arr);
        
        int count = 0;
        
        count += upper_bound(arr.begin(),arr.begin()+pivot,x)-arr.begin();
        count += upper_bound(arr.begin()+pivot, arr.end(),x) - (arr.begin()+pivot);
        
        return count;
    }
    private:
    
    int findPivot(vector<int>& arr){
        int low = 0, high = arr.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(arr[mid] > arr[high]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    
};