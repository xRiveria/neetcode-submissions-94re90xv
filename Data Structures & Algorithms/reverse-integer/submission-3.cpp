class Solution {
public:
    int reverse(int x) {
        int original = x;
        std::string intString = std::to_string(x);
        std::reverse(intString.begin(), intString.end()); // If negative, note that the negastivre sign is preserved. 
        long long result = stoll(intString); // Negative sign disappears since the sign is at the back.
        if (original < 0)
        {
            result *= -1;
        }

        // Check if the result fits in a 32-bit signed integer range.
        // The valid range of an integer is -2147483648 to 2147483647.
        // Falling out of this range makes it invalid. 
        if (result < -(1LL << 31) || result > (1LL << 31) - 1)
        {
            return 0;
        }

        return static_cast<int>(result);
    }
};
