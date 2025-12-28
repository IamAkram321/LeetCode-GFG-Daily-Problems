class Solution {
public: //T.C: O(n) and S.C: O(1)
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;
        int maxWater = 0;
        while(i<j){
            int h = min(height[i],height[j]);
            int w = j-i;
            int water=h*w;
            if(water>maxWater){
                maxWater = water;
            }
            height[i]<height[j]?i++:j--;
        }
        return maxWater;
    }
};