class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int result = nums[0];

        while (l <= r)
        {
            // The entire array is sortedonce more.
            if (nums[l] < nums[r])
            {
                result = std::min(result, nums[l]);
                break;
            }
            
            int middleIndex = l + ((r - l) / 2); // Always save the result.
            result = std::min(result, nums[middleIndex]);

            // If middleIndex >= right most, the minimum element is to the right. 
            if (nums[middleIndex] >= nums[r])
            {
                l = middleIndex + 1;
            }
            else // Else, we have something like 2 1 3 4 5. It means the answer is the left.
            {
                r = middleIndex - 1;
            }
        }

        return result;
    }
};
