class Solution {
public:
    int getSum(int a, int b) {
        // First iteration: compute all carries from the original addition
        // Second iteration: compute carries caused by the first carries
        // Third iteration: compute carries caused by those carries
        // Eventually no more carry remains
        // So it's not skipping the rightmost bit — it's doing all columns in parallel, then propagating carries.
        while (b != 0)
        {
            int carry = (a & b) << 1;  // a & b tells us where both bits are one, which creates a carry. Shifting left by 1 moves that carry to the next higher bit.
            a ^= b; // 1 + 1 = 0. 1 + 0 = 1. 0 + 1 = 1. 0 + 0 = 0.
            b = carry;
        }

        return a;
    }
};
