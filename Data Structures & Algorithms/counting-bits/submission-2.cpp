class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            // Use previous result. This makes sense we're pretty much scanning from right to left still and accumulating results per bit in the DP array.
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
