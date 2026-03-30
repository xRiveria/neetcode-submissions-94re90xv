class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;

        std::vector<int> cache(n + 1, 0);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            cache[i] = cache[i - 3] + cache[i - 2] + cache[i - 1]; 
        }

        return cache[n];
    }
};