class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> results(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            int current = i;
            while (current)
            {
                if (current & 1) results[i]++;
                current >>= 1;
            }
        }

        return results;
    }
};
