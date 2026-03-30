class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> inDegree(n, 0);
        std::vector<int> outDegree(n, 0);

        for (int i = 0; i < trust.size(); ++i)
        {
            outDegree[trust[i][0] - 1]++;
            inDegree[trust[i][1] - 1]++;
        }

        for (int i = 0; i < n; ++i)
        {
            if (outDegree[i] == 0 && inDegree[i] == (n - 1))
            {
                return (i + 1);
            }
        }

        return -1;
    }
};