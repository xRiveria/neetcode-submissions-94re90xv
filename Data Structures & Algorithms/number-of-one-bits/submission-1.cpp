class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n)
        {
            // When you perform a bitwise AND on n and n - 1, the rightmost 1 bit in n gets "cancelled out" because the corresponding bit in n - 1 is 0. 
            // All other bits to the left remain the same in both numbers, so the & operation preserves them. 
            n &= n - 1; // 1010 & (n - 1 = 1001) = 1000.
            result++;
        }

        return result;
    }
};
