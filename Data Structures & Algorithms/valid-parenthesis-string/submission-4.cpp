class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;
        // leftMin is the minimum possible number of unmatched '('.
        // leftMax is the maximum possible number of unmatched '('.
        // If at any point the maximum possible opens becomes negative, the string is invalid.
        // At the end, if the minimum possible opens is zero, the string can be valid
        for (char c : s)
        {
            if (c == '(')
            {
                leftMin++;
                leftMax++;
            }
            else if (c == ')')
            {
                leftMin--;
                leftMax--;
            }
            else
            {
                leftMin--;
                leftMax++;
            }

            if (leftMax < 0)
            {
                return false;
            }
            if (leftMin < 0)
            {
                leftMin = 0;
            }
        }

        return leftMin == 0;
    }
};
