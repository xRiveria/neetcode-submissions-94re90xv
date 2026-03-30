class Solution {
public:
    int findMin(vector<int> &nums) {
        // Property of sorted arrays is that it is sorted if value[left] < value[right]. This is the only property that makes sense in a sorted array.
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
