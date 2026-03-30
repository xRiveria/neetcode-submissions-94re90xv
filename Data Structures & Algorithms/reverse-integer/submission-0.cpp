class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;

            // Check overflow.
            // INT_MAX = 2147483647
            // INT_MIN = −2147483648
            // INT_MAX / 10 = 214748364. result * 10 + digit if exceeds, won't work.
            // Same for if result == INT_MAX/10. Because * 10 and adding digit won't work if value > 7. It will overflow.
            if (result > INT_MAX / 10 || 
               (result == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || 
               (result == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            result = result * 10 + digit;
        }

        return result;
    }
};
