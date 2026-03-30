class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // We use the longer text.
        if (text1.size() < text2.size())
        {
            std::swap(text1, text2);
        }
        // We don't need the entire 2D table to be cached as results only depend on the current and next row.
        // We will keep a prev array for the next row and a curr array for the current row.
        // We swap them after each row is processed.
        std::vector<int> prev(text2.size() + 1, 0);
        std::vector<int> current(text2.size() + 1, 0);

        for (int i = text1.size() - 1; i >= 0; --i)
        {
            for (int j = text2.size() - 1; j >= 0; --j)
            {
                if (text1[i] == text2[j])
                { 
                    // If equal, set current to be 1 + the cached results of the previous row.
                    // Later, current becomes previous.
                    current[j] = 1 + prev[j + 1];
                }
                else
                {
                    // Otherwise, we have two valid choices.
                    // If we skip text1, that result is already stored in prev[j].
                    // If we skip text2, that result is alread stored in current[j + 1].
                    // current[j + 1] is already computed in the same row. The inner loop.
                    // prev[j] comes from previous row which computed (i + 1).
                    current[j] = std::max(current[j + 1], prev[j]);
                }
            }

            std::swap(prev, current);
        }

        return prev[0];
    }
};
