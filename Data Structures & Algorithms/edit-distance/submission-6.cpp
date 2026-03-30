class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // We work with m as the larger vector.
        // This means word2/n is smaller.
        if (m < n)
        {
            std::swap(m, n);
            std::swap(word1, word2);
        }

        // dp[j] → represents dp[i+1][j] 
        // nextDp[j] → represents dp[i][j]
        std::vector<int> dp(n + 1), nextDp(n + 1);
        // When word1 is exhausted, we need to insert all remaining characters of word2[j:].
        for (int j = 0; j <= n; ++j)
        {
            dp[j] = n - j;
        }

        for (int i = m - 1; i >= 0; --i)
        {
            // When word2 is exhausted, we must delete all remaining characters of word1[i:].
            nextDp[n] = m - i;
            for (int j = n - 1; j >= 0; --j)
            {
                if (word1[i] == word2[j])
                {
                    nextDp[j] = dp[j + 1];
                }
                else
                {
                    // Delete, Insert, Replace
                    // (i+1, j), (i, j+1), (i+1, j+1).
                    nextDp[j] = 1 + std::min({ dp[j], nextDp[j + 1], dp[j + 1] });
                }
            }
            dp = nextDp;
        }

        return dp[0];
    }
};
