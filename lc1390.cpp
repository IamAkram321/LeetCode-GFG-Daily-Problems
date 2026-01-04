class Solution {
public: //T.C: O(n * sqrt(max(nums))) and S.C: O(1)
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            vector<int> temp;
            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    temp.push_back(i);
                    if(i!=num/i){
                        temp.push_back(num/i);
                    }
                }
                if(temp.size()>4) break;
            }
            if(temp.size()==4){
                sum += accumulate(temp.begin(),temp.end(),0);
            }
        }
        return sum;
    }
};