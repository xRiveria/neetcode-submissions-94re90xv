class Solution {
public:
    std::vector<std::string> m_Results;
    // Two conditions here.
    // Only recurse if...
    // 1) There are open brackets addable...
    // 2) If there are lesser closeBrackets than openBrackets.
    void DFS(int openCount, int closeCount, std::string& result)
    {
        if (openCount == 0 && closeCount == 0)
        {
            m_Results.push_back(result);
            return;
        }

        if (openCount != 0)
        {
            result += "(";
            DFS(openCount - 1, closeCount, result);
            result.pop_back();
        }

        // Because we're reducting!
        if (closeCount > openCount)
        {
            result += ")";
            DFS(openCount, closeCount - 1, result);
            result.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        std::string result = "";
        DFS(n, n, result);
        return m_Results;
    }
};
