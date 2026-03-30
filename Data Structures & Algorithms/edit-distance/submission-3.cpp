class Solution {
public:
    std::map<std::pair<int, int>, int> result;
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        return DFS(0, 0, word1, word2, m, n);
    }

    // Returns changes. 
    int DFS(int i, int j, std::string& w1, std::string& w2, int m, int n)
    {
        if (i == m) return n - j;
        if (j == n) return m - i;

        if (result.count({ i, j }))
        {
            return result[{ i, j}];
        }

        if (w1[i] == w2[j]) // Nothing needs to be done.
        {
            result[{ i, j }] = DFS(i + 1, j + 1, w1, w2, m, n);
        }
        else
        {
            // Delete, Insert, Replace. We don't modify w1, w2 physically at any point. 
            int results = std::min(DFS(i + 1, j, w1, w2, m, n), DFS(i, j + 1, w1, w2, m, n));
            results = std::min(results, DFS(i + 1, j + 1, w1, w2, m, n));
            result[{ i, j }] = results + 1;
        }

        return result[{ i, j }];
    }
};
