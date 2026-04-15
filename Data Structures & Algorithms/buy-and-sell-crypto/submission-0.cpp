class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int finalProfit = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > minPrice){
                finalProfit = max(finalProfit, prices[i] - minPrice);
            } else {
                minPrice = prices[i]; 
            }
        }
        return finalProfit;
    }
};
