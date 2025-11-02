/*
    T.C: O(n) && S.C: O(2) ~ O(1)
*/
class Solution {
public: //Given an array fruits, find the length of the longest subarray that contains at most 2 distinct types of fruits. 
    int totalFruit(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>mpp;
        int left = 0;
        int maxLength = 0;
        for(int right=0;right<n;right++){
            mpp[nums[right]]++;
            while(mpp.size()>2){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            maxLength = max(maxLength,right-left+1);
        }
        return maxLength;

    }
};