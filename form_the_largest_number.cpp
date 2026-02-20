class Solution {
  public:
    string findLargest(vector<int> &arr) {
        
        vector<string> nums;
        
        for(int i=0;i<arr.size();i++){
            nums.push_back(to_string(arr[i]));
        }
        sort(nums.begin(),nums.end(),[](string& a, string& b){
            return a+b > b+a;
        });
        string result = "";
        for(string s : nums){
            result += s;
        }
        if(result[0]=='0') return "0";
        return result;
    }
};