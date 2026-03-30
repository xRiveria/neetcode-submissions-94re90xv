class Solution {
public:
    int reverse(int x) {
        long result = Record(std::abs(x), 0) * (x < 0 ? -1 : 1);
        if (result < INT_MIN || result > INT_MAX)
        {
            return 0;
        }

        return (int)result;
    }

    long Record(int n, long rev)
    {
        if (n == 0)
        {
            return rev;
        }

        rev = (rev * 10) + (n % 10);
        return Record(n / 10, rev);
    }
};
