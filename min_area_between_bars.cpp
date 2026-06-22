class Solution {
  public: //T.C: O(N) and S.C: O(1)
    int maxArea(vector<int> &height) {
       int n = height.size();
       int i=0;
       int j=n-1;
       int max_area=0;
       while(i<j){
           int ht = min(height[i],height[j]);
           int width=j-i-1;
           max_area = max(ht*width,max_area);
           if(height[i]<height[j]){
               i++;
           }else{
               j--;
           }
       }
       return max_area;
       
    }
};