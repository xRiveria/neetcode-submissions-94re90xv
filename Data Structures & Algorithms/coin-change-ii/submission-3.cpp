class Solution {
public:
    int uniqueC = 0;
    std::map<std::pair<int, int>, int> cache; // Cache stores current combinations.

    int DFS(std::vector<int>& coins, int amount, int i)
    {
        if (amount < 0)
        {
            return 0;
        }

        if (amount == 0)
        {
            return 1;
        }

        if (cache.count({ i, amount })) return cache[{ i, amount }];
        
        int currentCombinations = 0;
        for (int j = i; j < coins.size(); ++j)
        {
            currentCombinations += DFS(coins, amount - coins[j], j);
        }

        cache[{ i, amount }] = currentCombinations;
        return currentCombinations;
    }

    int change(int amount, vector<int>& coins) {
        std::sort(coins.begin(), coins.end()); // Sort the coins.
        return DFS(coins, amount, 0);
    }
};
