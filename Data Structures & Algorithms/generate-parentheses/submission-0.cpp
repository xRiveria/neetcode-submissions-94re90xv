class Solution {
public:
    std::vector<std::string> m_Results;
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
            openCount--;
            DFS(openCount, closeCount, result);
            result.pop_back();
            openCount++;
        }

        // Because we're reducting!
        if (closeCount > openCount)
        {
            result += ")";
            closeCount--;
            DFS(openCount, closeCount, result);
            result.pop_back();
            closeCount++;
        }
    }

    vector<string> generateParenthesis(int n) {
        std::string result = "";
        DFS(n, n, result);
        return m_Results;
    }
};
