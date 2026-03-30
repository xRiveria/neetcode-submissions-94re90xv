class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> vals; // Greater by default. Keep lesser.
        for (int i = 0; i < nums.size(); ++i)
        {
            vals.push(nums[i]);
            if (vals.size() > k)
            {
                vals.pop();
            }
        }

        return vals.top();
    }
};
