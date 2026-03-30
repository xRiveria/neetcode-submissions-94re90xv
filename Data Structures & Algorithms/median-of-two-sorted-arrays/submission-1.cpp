class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int>& arrayA = nums1;
        std::vector<int>& arrayB = nums2;
        int totalElements = arrayA.size() + arrayB.size();
        // The +1 is there to make the math work uniformly for both odd and even total lengths when you split the arrays into left and right halves.
        int halfElements = (totalElements + 1) / 2;

        if (arrayB.size() < arrayA.size())
        {
            std::swap(arrayA, arrayB);
        }

        int l = 0;
        int r = arrayA.size();

        while (l <= r)
        {
            int i = l + ((r - l) / 2); // Left bound of A.
            int j = halfElements - i; // Left bound of B.

            int aLeft = i > 0 ? arrayA[i - 1] : INT_MIN;
            int aRight = i < arrayA.size() ? arrayA[i] : INT_MAX;
            int bLeft = j > 0 ? arrayB[j - 1] : INT_MIN;
            int bRight = j < arrayB.size() ? arrayB[j] : INT_MAX;

            if (aLeft <= bRight && bLeft <= aRight)
            {
                if (totalElements % 2 != 0)
                {
                    return std::max(aLeft, bLeft);
                }
                return (std::max(aLeft, bLeft) + std::min(aRight, bRight)) / 2.0f;
            }
            else if (aLeft > bRight)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }

        return -1;
    }
};
