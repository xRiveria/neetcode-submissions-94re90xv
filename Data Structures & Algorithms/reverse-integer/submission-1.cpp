class Solution {
public:
    int reverse(int x) {
        int original = x;
        std::string intString = std::to_string(x);
        std::reverse(intString.begin(), intString.end());
        long long result = stoll(intString);
        if (original < 0)
        {
            result *= -1;
        }

        if (result < -(1LL << 31) || result > (1LL << 31) - 1)
        {
            return 0;
        }

        return static_cast<int>(result);
    }
};
