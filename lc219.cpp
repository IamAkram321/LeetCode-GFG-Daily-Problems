class Solution {
public: //T.C: O(n) and S.C:O(1) , it can be solved using map but there we have to count each element and in this hash+sliding window only last k we have
//to store that's why this is better
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> st;

        int left = 0;
        for(int right=0;right<nums.size();right++){
            if(st.count(nums[right])) return true;
            st.insert(nums[right]);
            if(st.size()>k){
                st.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
//map approach but space O(n)

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> mp; // value -> last index

//         for (int i = 0; i < nums.size(); i++) {
//             if (mp.count(nums[i])) {
//                 if (i - mp[nums[i]] <= k) {
//                     return true;
//                 }
//             }
//             mp[nums[i]] = i; // update last seen index
//         }
//         return false;
//     }
// };
