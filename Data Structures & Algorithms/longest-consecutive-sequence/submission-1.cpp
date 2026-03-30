class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        std::unordered_map<int, int> values;
        int longestValue = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int value = nums[i];
            if (!values[value])
            {
                int currentStreak = values[value - 1] + values[value + 1] + 1; // Include itself.
                values[value] = currentStreak;
                values[value - values[value - 1]] = currentStreak;
                values[value + values[value + 1]] = currentStreak;
                longestValue = std::max(longestValue, currentStreak);
            }
        }

        return longestValue;

/*
        std::unordered_set<int> values(nums.begin(), nums.end());
        int currentLongest = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int value = nums[i] + 1;
            int currentStreak = 1;
            while (values.count(value))
            {
                currentStreak++;
                value++;
            }
            currentLongest = std::max(currentLongest, currentStreak);
        }

        return currentLongest;
*/
    }
};
