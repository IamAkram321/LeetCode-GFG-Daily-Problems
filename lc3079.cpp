class Solution {
public: //T.C: O(n) and S.C: O(1)
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int a = nums[i];
            string str = to_string(a);
            int maxi = 0;
            while(a!=0){
                int temp = a%10;
                maxi = max(maxi,temp);
                a/=10;
            }
            for(int j=0;j<str.size();j++){
                str[j] = maxi + '0';
            }
            sum += stoi(str);
        }
        return sum;
    }
};