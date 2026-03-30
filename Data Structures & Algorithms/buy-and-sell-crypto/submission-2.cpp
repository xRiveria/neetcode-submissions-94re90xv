class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minimumBuyPrice = prices[0];
        int maxProfitThusFar = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            int profit = prices[i] - minimumBuyPrice;
            maxProfitThusFar = std::max(profit, maxProfitThusFar);
            minimumBuyPrice = std::min(minimumBuyPrice, prices[i]);
        }

        return maxProfitThusFar;
    }
};
