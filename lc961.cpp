/*class Solution {
public: //T.C: O(n) and S.C: O(n)
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int n : nums){
            mpp[n]++;
        }
        for(auto it: mpp){
            if(it.second == n/2) return it.first;
        }
        return -1;
    }
};
*/

/*class Solution {
public: //T.C: O(n) and S.C: O(n)
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int n : nums){
            if(st.cound(n)) return n;
            else st.insert(n);
        }
        return -1;
    }
};
*/

class Solution {
public: //T.C: O(n) and S.C: O(1)
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]) return nums[i];
        }
        return nums[n-1];
    }
};