class Solution {
public: //T.C: O(n) and S.C: O(1)
    vector<int> twoSum(vector<int>& arr, int target) {

        int i=0, j=arr.size()-1;
        while(i<j){
            int sum = arr[i]+arr[j];
            if(sum == target) return {i+1,j+1};
            else if(sum < target){
                i++;
            }else{
                j--;
            }
        }
        return {-1,-1};
    }
};