class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        int result = 0;

        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if ((long long)mid * mid < x)
            {
                // This is a valid candidate as we want an answer that is closest to.
                // We will store it and search for a larger value. 
                l = mid + 1;
                result = mid;
            }
            else if ((long long)mid * mid > x)
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return result;
    }
};