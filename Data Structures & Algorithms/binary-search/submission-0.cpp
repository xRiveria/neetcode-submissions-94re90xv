class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftBounds = 0;
        int rightBounds = nums.size() - 1;

        while (leftBounds <= rightBounds)
        {
            int middleIndex = leftBounds + ((rightBounds - leftBounds) / 2);
            if (nums[middleIndex] == target)
            {
                return middleIndex;
            }
            else if (nums[middleIndex] > target)
            {
                rightBounds = middleIndex - 1;
            }
            else
            {
                leftBounds = middleIndex + 1;
            }
        }

        return -1;
    }
};
