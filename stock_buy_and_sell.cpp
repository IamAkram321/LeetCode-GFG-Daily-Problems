class Solution {
  public: //T.C: O(n) and S.C: O(1)
    int maxProfit(vector<int> &prices) {
        
        int n = prices.size();
        
        int maxProfit = 0;
        int minPrice = INT_MAX;
        
        for(int x : prices){
            if(x < minPrice){
                minPrice = x;
            }else{
                maxProfit = max(maxProfit,x-minPrice);
            }
            
        }
        return maxProfit;
    }
};
