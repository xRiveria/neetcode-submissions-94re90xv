/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = INT_MAX;

        while (l < r)
        {
            int middle = l + ((r - l) / 2);
            int result = guess(middle);
            if (result == 0)
            {
                return middle;
            }
            else if (result == -1)
            {
                r = middle;
            }
            else
            {
                l = middle + 1;
            }
        }

        return INT_MAX;
    }
};