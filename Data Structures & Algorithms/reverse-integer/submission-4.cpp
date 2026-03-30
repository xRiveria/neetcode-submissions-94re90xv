class Solution {
public:
    int reverse(int x) {
        int minConstraint = INT_MIN;
        int maxConstraint = INT_MAX; // Cannot use 2^31 - 1 as ^ becomes XOR in C++.

        int result = 0;
        while (x != 0)
        {
            int lastDigit = x % 10;
            x /= 10;

            if ((result > maxConstraint / 10) || (result == maxConstraint / 10 && lastDigit > maxConstraint % 10))
            {
                return 0;
            }

            if ((result < minConstraint / 10) || (result == minConstraint / 10 && lastDigit < minConstraint % 10))
            {
                return 0;
            }

            result = (result * 10) + lastDigit;
        }

        return result;
    }
};
