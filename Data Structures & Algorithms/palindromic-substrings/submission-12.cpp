class Solution {
public:
    int countSubstrings(string s) {
        int result = 0, n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                // We have a palindrome if...
                // The end characters match or if...
                // The inside substring s[i + 1][j - 1] is also a palindrome or if length <= 2, which is always a palindrome. 
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    result++;
                }
            }
        }

        return result;
    }
};
