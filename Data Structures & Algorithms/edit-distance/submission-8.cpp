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

        std::vector<int> dp(n + 1);
        // When word1 is exhausted, we need to insert all remaining characters of word2[j:].
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = n - i;
        }

        for (int i = m - 1; i >= 0; --i)
        {
            // When word2 is exhausted, we must delete all remaining characters of word1[i:].
           int nextDp = dp[n];
           dp[n] = m - i;

           for (int j = n - 1; j >= 0; --j)
           {
            int temp = dp[j];
            if (word1[i] == word2[j])
            {
                dp[j] = nextDp;
            } 
            else
            {
                dp[j] = 1 + std::min({ dp[j], dp[j + 1], nextDp });
            }
                       nextDp = temp;

           }
        }

        return dp[0];
    }
};
