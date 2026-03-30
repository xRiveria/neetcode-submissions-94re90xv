class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
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
    }
};
