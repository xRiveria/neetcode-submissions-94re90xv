class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        // l < r means we want to keep a single element left.
        // For this, we usually set r = middleElement, instead of middleElement - 1.
        // This style is very popular for “first position”, “last position”, or “lower/upper bound” problems.

        // l <= r means we want to reduce the range to empty. This means our answer would be l. 
        // We need to recognize these patterns.
        // l <= r → keep searching while there are elements to check.
        // l < r → keep shrinking until only one possible index remains.
        while (l < r)
        {
            int mid = l + ((r - l) / 2);
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;

    }
};