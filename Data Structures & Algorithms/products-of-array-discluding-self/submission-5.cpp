class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> finalValues(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            finalValues[i] = finalValues[i - 1] * nums[i - 1];
        }

        int postfixValue = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            finalValues[i] *= postfixValue;
            postfixValue *= nums[i];
        }

        return finalValues;


        /*
        std::vector<int> prefixSum(nums.size());
        std::vector<int> postfixSum(nums.size());
        std::vector<int> results(nums.size());

        prefixSum[0] = 1;
        postfixSum[nums.size() - 1] = 1;
        // 1 2 3 4 5
        // 1 2 6 24 120
        for (int i = 1; i < nums.size(); ++i)
        {
            prefixSum[i] = (prefixSum[i - 1] * nums[i - 1]);
        }

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            postfixSum[i] = (postfixSum[i + 1] * nums[i + 1]);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            results[i] = prefixSum[i] * postfixSum[i]; 
        }

        return results;
        */

        /*
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
        */

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
