class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1));
        for (int i = text1.size() - 1; i >= 0; --i)
        {
            for (int j = text2.size() - 1; j >= 0; --j)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][0];
    }
};
