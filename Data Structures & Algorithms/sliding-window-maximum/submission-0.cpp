class Solution {
public:
    std::vector<int> results;

    void FindMaximum(int* leftPtr, int* rightPtr)
    {
        int maximumValue = INT_MIN;
        while (leftPtr != rightPtr)
        {   
            maximumValue = std::max(maximumValue, *leftPtr);
            leftPtr++;
        }
        maximumValue = std::max(maximumValue, *leftPtr);
        results.push_back(maximumValue);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j = k - 1;

        while (i < nums.size())
        {
            if (j >= nums.size())
            {
                break;
            }
            FindMaximum(&nums[i], &nums[j]);
            i++, j++;
        }

        return results;
    }
};
