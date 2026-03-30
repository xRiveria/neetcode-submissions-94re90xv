class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0; // best up to house i - 2
        int rob2 = 0; // best up to house i - 1

        for (auto& num : nums)
        {
            int tempMax = std::max(num + rob1, rob2);
            rob1 = rob2; // Holds the what if no rob sce
            rob2 = tempMax;
        }

        return rob2;
    }
};
