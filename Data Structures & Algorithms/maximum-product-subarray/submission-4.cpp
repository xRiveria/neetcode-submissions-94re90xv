class Solution {
public:
    int m_LargestProduct = INT_MIN;

    int maxProduct(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            int product = nums[i];
            m_LargestProduct = std::max(m_LargestProduct, product);

            for (int j = i + 1; j < nums.size(); ++j)
            {
                product *= nums[j];
                m_LargestProduct = std::max(m_LargestProduct, product);
            }
        }

        return m_LargestProduct;
    }
};
