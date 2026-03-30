class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_Values;
    int m_K;
    KthLargest(int k, vector<int>& nums) {
        m_K = k;
        for (int i = 0; i < nums.size(); ++i)
        {
            m_Values.push(nums[i]);

            if (m_Values.size() > k)
            {
                m_Values.pop();
            }
        }

    }
    
    int add(int val) {
        m_Values.push(val);
        if (m_Values.size() > m_K)
        {
            m_Values.pop();
        }
        return m_Values.top();
    }
};
