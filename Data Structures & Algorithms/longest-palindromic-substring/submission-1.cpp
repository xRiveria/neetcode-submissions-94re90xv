class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.size();
       int resultsIndex = 0;
       int resultsLength = 0;

       // dp[i][j] = true if the substring s[i..j] is a palindrome.
       std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
       // We fill dp from bottom to top so that when we compare dp[i][j],the values at dp[i + 1][j - 1] is already known.
       for (int i = n - 1; i >= 0; i--)
       {
            for (int j = i; j < n; j++)
            {
                // We have a substring when the end characters match such that s[i] == s[j].
                // And if the inside part is also a palindrome dp[i + 1][j - 1].
                // If the length is 1 2 or 3, then matching ends is enough bause the middle is empty or a single character.
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    if (resultsLength < (j - i + 1))
                    {
                        resultsIndex = i;
                        resultsLength = j - i + 1;
                    }
                }
            }
       }

       return s.substr(resultsIndex, resultsLength);
    }
};
