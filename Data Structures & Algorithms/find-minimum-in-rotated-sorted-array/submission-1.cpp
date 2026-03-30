class Solution {
public:
    int findMin(vector<int> &nums) {
        int smallestNumber = INT_MAX;
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
        {
            int middleIndex = i + ((j - i) / 2);
            smallestNumber = std::min(smallestNumber, nums[middleIndex]);
            if (nums[middleIndex] < nums[j])
            {
                // Number must be to the left.
                j = middleIndex - 1;
            }
            else
            {
                i = middleIndex + 1;
            }
        }

        return smallestNumber;
    }
};
