class Solution {
public:
    int DFS(int remaining, std::vector<int>& perfectSquares, std::vector<int>& cache)
    {
        if (remaining == 0) return 0; // There are 0 ways to form a remaining sum of 0, because there is perfect square of 0.
        if (cache[remaining] != -1) return cache[remaining];

        int best = INT_MAX;
        for (int s : perfectSquares)
        {
            if (s > remaining) break; // All larger values past this point are bigger.
            best = std::min(best, 1 + DFS(remaining - s, perfectSquares, cache));
        }

        return cache[remaining] = best;
    }

    int numSquares(int n) {
        std::vector<int> perfectSquares;
        for (int i = 1; i * i <= n; ++i)
        {
            perfectSquares.push_back(i * i);
        }
        std::vector<int> cache(n + 1, -1); // Up to N including 0.
        return DFS(n, perfectSquares, cache);
    }
};