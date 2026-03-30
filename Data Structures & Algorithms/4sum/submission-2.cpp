class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        // The two-pointer technique only works on a sorted array. This allows us to get unique quindriplets as well.
        // This is because in sorted arrays, same values are next to one another, allowing us to skip them easily.
        sort(nums.begin(), nums.end());
        // We want  unique quadruplets. This means we skip duplicates across the board! 
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++; // Ignore dupes.
                        while (left < right && nums[right] == nums[right + 1]) right--; // Ignore dupes.
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};