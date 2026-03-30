class Solution {
public:
    int m_MinimumCoins = INT_MAX;
    void DFS(std::vector<int>& coins, int neededAmount, int currentAmount, int i, int currentCoinCount)
    {
        if (currentAmount > neededAmount || i >= coins.size())
        {
            return;
        }

        if (currentAmount == neededAmount)
        {
            m_MinimumCoins = std::min(m_MinimumCoins, currentCoinCount);
            return;
        }

        // Use this coin again.
        DFS(coins, neededAmount, currentAmount + coins[i], i, currentCoinCount + 1);
        // Skip it.
        DFS(coins, neededAmount, currentAmount, i + 1, currentCoinCount);
    }

    int coinChange(vector<int>& coins, int amount) {
        DFS(coins, amount, 0, 0, 0);
        if (m_MinimumCoins == INT_MAX)
        {
            return -1;
        }
        return m_MinimumCoins;
    }
};
