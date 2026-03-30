class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Greedy works here because consecutive daily agains are equivalent to one larger transaction.
        // Buying at 1, selling at 5, equals to buying at 1, selling at 3, buying at 3 and selling at 5.
        // When using the greedy approach, only add the difference when prices[i] > prices[i-1]. 
        //  Adding negative differences (price drops) reduces your profit incorrectly.
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }

        return profit;
    }
};