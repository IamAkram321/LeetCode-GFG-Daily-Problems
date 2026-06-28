class Solution {
public: //T.C: O(n) and S.C:O(1)
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int max_water=0;
        while(i<j){
            int ht=min(height[i],height[j]);
            int wt=j-i;
            max_water=max(max_water,ht*wt);
            height[i]<height[j]?i++:j--;
        }
        return max_water;
    }
};