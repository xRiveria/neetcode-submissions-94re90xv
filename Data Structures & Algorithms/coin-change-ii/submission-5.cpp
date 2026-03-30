class Solution {
public:
    int uniqueC = 0;
    std::map<std::pair<int, int>, int> cache; // Cache stores current combinations.

    int DFS(std::vector<int>& coins, int amount, int i)
    {
        if (amount == 0)
        {
            return 1;
        }

        if (i >= coins.size())
        {
            return 0;
        }

        if (cache.count({ i, amount })) return cache[{ i, amount }];
        
        int currentCombinations = 0;
        if (amount >= coins[i])
        {
            currentCombinations = DFS(coins, amount, i + 1); // Skip
            currentCombinations += DFS(coins, amount - coins[i], i); // Reuse
        }

        cache[{ i, amount }] = currentCombinations;
        return currentCombinations;
    }

    int change(int amount, vector<int>& coins) {
        std::sort(coins.begin(), coins.end()); // Sort the coins.
        return DFS(coins, amount, 0);
    }
};
