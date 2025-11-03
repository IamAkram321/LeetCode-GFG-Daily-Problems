class Solution {
public: // T.C : O(n) and S.C : O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0, minPrice = INT_MAX;
        for(int price : prices){
            if(price < minPrice){
                minPrice = price;
            }else{
                maxProfit = max(maxProfit, price - minPrice);
            }
        }
        return maxProfit;
    }
};