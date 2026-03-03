#include <bits/stdc++.h>
using namespace std;
//T.C: O(n) and S.C: O(n)
class Solution {
public:
    int totalElements(vector<int>& arr) {
        unordered_map<int, int> count;
        int left = 0, maxLength = 0;

        for (int right = 0; right < arr.size(); ++right) {
            count[arr[right]]++;
            // Shrinking the window if more than 2 distinct integers
            while (count.size() > 2) {
                count[arr[left]]--;
                if (count[arr[left]] == 0) {
                    count.erase(arr[left]);
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
