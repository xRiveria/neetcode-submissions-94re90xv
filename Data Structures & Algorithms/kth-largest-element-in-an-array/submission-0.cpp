class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> m_Values;
        for (int i = 0; i < nums.size(); ++i)
        {
            m_Values.push(nums[i]);
            if (m_Values.size() > k)
            {
                m_Values.pop();
            }
        }

        return m_Values.top();
    }
};
