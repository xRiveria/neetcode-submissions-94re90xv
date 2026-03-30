class Solution {
public:
    std::vector<std::vector<int>> results;

    void Try(std::vector<int>& values, int i, int currentValue, std::vector<int> currentNumbers, int target)
    {
        if (currentValue == target)
        {
            results.push_back(currentNumbers);
            return;
        }

        for (int j = i; j < values.size(); ++j)
        {
            if (currentValue + values[j] > target)
            {
                return;
            }

            currentNumbers.push_back(values[j]);
            Try(values, j, currentValue + values[j], currentNumbers, target);
            currentNumbers.pop_back();
        }


    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        Try(nums, 0, 0, {}, target);
        return results;
    }
};
