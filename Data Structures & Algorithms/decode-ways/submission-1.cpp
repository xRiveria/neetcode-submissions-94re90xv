class Solution {
public:
    std::unordered_map<int, int> dp; // At i, how many ways to decode?

    int DFS(const std::string& s, int currentIndex)
    {
        if (dp.count(currentIndex))
        {
            return dp[currentIndex];
        }

        // 0 cannot be mapped into a letter.
        if (s[currentIndex] == '0')
        {
            return 0;
        }

        // Always try decoding one digit.
        int result = DFS(s, currentIndex + 1);
        // If two digits form a valid number (10-26), also try it.
        // Note that we're simply bypassing the number here. We cannot call DFS on the 0 as it will return 0. 
        if (currentIndex < s.size() - 1)
        {
            // If two digits form a valid number (10-26), also try → dfs(i + 2)
            if (s[currentIndex] == '1' || (s[currentIndex] == '2' && s[currentIndex + 1] < '7'))
            {
                result += DFS(s, currentIndex + 2);
            }
        }

        dp[currentIndex] = result;

        return result;
    }

    int numDecodings(string s) {
        dp[s.size()] = 1; // When dfs(i) reaches the end of the string (i == s.size()), it means you've successfully decoded the entire string, so that path counts as one valid decoding. Reaching the end means you formed one valid decoding — so count it.
        return DFS(s, 0);
    }
};
