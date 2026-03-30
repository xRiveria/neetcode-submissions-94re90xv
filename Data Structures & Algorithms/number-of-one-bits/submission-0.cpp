class Solution {
public:
    int hammingWeight(uint32_t n) {
        int totalOneBits = 0;
        // An int has 32 bits.
        for (int i = 0; i < 32; ++i)
        {
            if (n & (1 << i))
            {
                totalOneBits++;
            }
        }
    
        return totalOneBits;
    }
};
