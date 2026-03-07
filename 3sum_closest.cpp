class Solution {
public:
    /*int threeSumClosest(vector<int>& nums, int target) {
        //T.C: O(N*N*N)
        int n = nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int sum  = nums[i]+nums[j]+nums[k];
                    if(abs(target-sum) < abs(target-closest)){
                        closest = sum;
                    }
                }
            }
        }
        return closest;
    }*/
    int threeSumClosest(vector<int>& nums, int target) {
        //T.C: O(nlogn) + (n*n) ~ O(n^2)
        int n = nums.size();
        sort(begin(nums),end(nums)); //O(nlogn)
        int closest = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){ //O(n)
            int j=i+1;
            int k=n-1;
            while(j<k){ //o(n)
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum) < abs(target-closest)){
                    closest = sum;
                }else if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return closest;
    }
};