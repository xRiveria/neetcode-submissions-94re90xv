class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxAreaThusFar = INT_MIN;
        while (i <= j)
        {
            int leftHeight = heights[i];
            int rightHeight = heights[j];
            int minimumHeight = std::min(leftHeight, rightHeight);
            maxAreaThusFar = std::max(maxAreaThusFar, (minimumHeight * (j - i)));

            if (leftHeight < rightHeight)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxAreaThusFar;
    }
};
