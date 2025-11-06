class Solution {
public: //T.C: O(n) and S.C: O(1)
    bool increasingTriplet(vector<int>& arr) {
        int n = arr.size();
        // int count = 0;
        // for(int i=0;i<n-1;i++){
        //     if(arr[i+1] > arr[i]){
        //         count++;
        //     }else{
        //         count = 1;
        //     }
        // }
        // return count >= 3 ? true : false;

        // for(int i=0;i<n-1;i++){
        //     int num = arr[i];
        //     for(int j=i+1;j<n;j++){
        //         if(arr[j] > num){
        //             count++;
        //             num = arr[j];
        //         }
        //     }
        // }
        // return count >= 3 ? true : false;

        //greedy
        int first_smallest = INT_MAX, second_smallest = INT_MAX;
        for(int num : arr){
            if(num <= first_smallest){
                first_smallest = num;
            }else if(num <= second_smallest){
                second_smallest = num;
            }else{
                return true;
            }
        }
        return false;
    }
};