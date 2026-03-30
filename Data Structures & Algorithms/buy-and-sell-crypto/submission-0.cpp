class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumValue = prices[0];
        int maximumProfit = INT_MIN;
        for (int i = 1; i < prices.size(); ++i)
        {
            int currentProfit = prices[i] - minimumValue;
            maximumProfit = std::max(maximumProfit, currentProfit);
            minimumValue = std::min(minimumValue, prices[i]);
        }
        
        if (maximumProfit <= 0)
        {
            return 0;
        }
        return maximumProfit;
        
    }
};
