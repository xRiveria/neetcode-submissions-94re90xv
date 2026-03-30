class Solution {
public:
    int tribonacci(int n) {
        int cache[3] = { 0, 1, 1 };
        for (int i = 3; i <= n; ++i)
        {
            cache[i % 3] = cache[0] + cache[1] + cache[2];
        }

        return cache[n % 3];
    }
};