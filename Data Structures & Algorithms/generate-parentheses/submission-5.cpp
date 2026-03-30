class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::vector<string>> results(n + 1);
        results[0] = { "" };

        for (int k = 0; k <= n; ++k)
        {
            for (int i = 0; i < k; ++i)
            {
                for (const std::string& left : results[i])
                {
                    for (const std::string& right : results[k - i - 1])
                    {
                        results[k].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return results[n];
    }
};
