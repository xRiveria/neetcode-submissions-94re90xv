class Solution {
public:
    int minDistance(string word1, string word2) {
        // Let dp[i][j] represent the minimum number of operations to convert word1[i:] into word2[j:].
        std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        // If word1 is exhausted, insert the rest of the characters from word2.
        for (int j = 0; j <= word2.size(); ++j)
        {
            // For example, if we reached the end of word1 and j is at 0, we need to insert word2.length characters.
            // If word2.length == word1.length, we need insert 0 characters. 
            dp[word1.length()][j] = word2.length() - j;
        }

        // If word2 is exhausted, delete the rest of the characters from word1. 
        for (int i = 0; i <= word1.size(); ++i)
        {
            dp[i][word2.length()] = word1.length() - i;
        }

        for (int i = word1.length() - 1; i >= 0; i--)
        {
            for (int j = word2.length() - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1]; // No operations needed.
                }
                else
                {
                    // Delete a character, insert a character, or replace. 
                    dp[i][j] = 1 + std::min(dp[i + 1][j], std::min(dp[i][j + 1], dp[i + 1][j + 1]));
                }
            }
        }

        return dp[0][0];
    }
};
