class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> finalValues;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                break; // Exit immedietely if our first value is already too large.
            }

            // Avoid adding a duplicate triplet.
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int leftIndex = i + 1;
            int rightIndex = nums.size() - 1;

            while (leftIndex < rightIndex)
            {
                int currentTarget = nums[i] + nums[leftIndex] + nums[rightIndex];
                if (currentTarget == 0)
                {
                    finalValues.push_back({ nums[i], nums[leftIndex], nums[rightIndex] });
                    leftIndex++;
                    rightIndex--;

                    // Always keep this to ensure we don't cross each other.
                    // If the value at leftIndex == (leftIndex - 1), we skip it to avoid duplicate answers again.
                    while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1])
                    {   
                        leftIndex++;
                    }

                    while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1])
                    {   
                        rightIndex--;
                    }
                }
                else if (currentTarget > 0)
                {
                    rightIndex--;
                }
                else
                {
                    leftIndex++;
                }
            }
        }

        return finalValues;
    }
};
