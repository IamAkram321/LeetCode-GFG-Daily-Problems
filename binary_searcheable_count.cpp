class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int count = 0;
        n = arr.size();
        for (int i = 0; i < n; i++) {
                int l = 0, r = n - 1;
                while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] == arr[i]) {
                    count++;
                    break;
                }
                if (arr[mid] < arr[i]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
             }
        }
        return count;
    }
};