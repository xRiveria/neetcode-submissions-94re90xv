class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        // Remember that when 2 identical numbers are XORed together, the result is 0. 
        for (int i = 0; i <= nums.size(); ++i)
        {
            result ^= i;
        }

        for (auto num : nums)
        {
            result ^= num;
        }

        return result;
    }
};
