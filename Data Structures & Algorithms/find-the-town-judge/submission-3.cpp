class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> degreeDelta(n + 1, 0);

        for (auto relation : trust)
        {
            degreeDelta[relation[0]]--;
            degreeDelta[relation[1]]++;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (degreeDelta[i] == (n - 1))
            {
                return i;
            }
        }

        return -1;
    }
};