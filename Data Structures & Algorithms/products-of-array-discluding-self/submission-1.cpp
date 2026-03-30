class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int zeroCount = 0;
        for (int value : nums)
        {
            if (value == 0)
            {
                zeroCount++;
            }
            else
            {
                totalProduct *= value;
            }
        }

        if (zeroCount >= 2)
        {
            return std::vector<int>(nums.size(), 0);
        }

        std::vector<int> finalResults;
        for (int i = 0; i < nums.size(); ++i)
        {
            // The only zero value in here.
            if (nums[i] == 0) 
            {
                finalResults.push_back(totalProduct);
                continue;
            }
            else
            {
                if (zeroCount != 0)
                {
                    finalResults.push_back(0);
                }
                else
                {
                    finalResults.push_back(totalProduct / nums[i]);
                }
            }
        }

        return finalResults;


        /*
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
        */
    }
};
