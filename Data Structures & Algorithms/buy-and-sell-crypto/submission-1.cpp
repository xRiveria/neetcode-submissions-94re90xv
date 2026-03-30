class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Keeps track of the currently most minimum bought stock prices.
        // We will set this at index 0.
        int minimumValue = prices[0];
        // Keep track of the maximum profit thus far.
        int maximumProfit = INT_MIN;
        for (int i = 1; i < prices.size(); ++i)
        {
            // Always calculate the profit using the current [i] as the selling price.
            int currentProfit = prices[i] - minimumValue;
            // Keep the max profit.
            maximumProfit = std::max(maximumProfit, currentProfit);
            // Keep track of this if the stock is cheaper than what we currently have.
            minimumValue = std::min(minimumValue, prices[i]);
        }
        
        // If our profit is negative, we just return 0.
        // This means we never found any profit anywhere.
        if (maximumProfit <= 0)
        {
            return 0;
        }
        return maximumProfit;
        
    }
};
