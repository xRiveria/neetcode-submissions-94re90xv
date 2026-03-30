class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute Force
        std::vector<int> finalValues;
        for (int i = 0; i < nums.size(); ++i)
        {
            int finalValue = 1;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i != j) // Skip (i).
                {
                    finalValue *= nums[j];
                }
            }

            finalValues.push_back(finalValue);
        }

        return finalValues;
    }
};
