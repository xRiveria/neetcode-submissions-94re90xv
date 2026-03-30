class Solution {
public:
    std::unordered_map<int, bool> values;

    bool DFS(std::string s, std::vector<std::string>& wordDic, int i)
    {
        if (i == s.size())
        {
            return true;
        }

        if (values.count(i))
        {
            return values[i];
        }

        for (int j = 0; j < wordDic.size(); ++j)
        {
            if (s.find(wordDic[j], i) == i)
            {
                if (DFS(s, wordDic, i + wordDic[j].size()))
                {
                    return values[i] = true;
                }
            }
        }

        return values[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return DFS(s, wordDict, 0);
    }
};
