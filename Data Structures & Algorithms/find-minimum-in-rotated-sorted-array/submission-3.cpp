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
            
            int middleIndex = l + ((r - l) / 2);
            result = std::min(result, nums[middleIndex]);
            
            if (nums[middleIndex] >= nums[r])
            {
                l = middleIndex + 1;
            }
            else
            {
                r = middleIndex - 1;
            }
        }

        return result;
    }
};
