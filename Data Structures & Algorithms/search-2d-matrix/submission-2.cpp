class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;

        while (i < matrix.size() && target > matrix[i][j])
        {
            i++;
        }

        // Now, find it. It must be within the row i.
        int row = i;
        int leftBound = 0;
        int rightBound = matrix[0].size() - 1;
        while (row < matrix.size() && leftBound <= rightBound)
        {
            int middleIndex = leftBound + ((rightBound - leftBound) / 2);
            if (matrix[i][middleIndex] == target)
            {
                return true;
            }
            else if (matrix[i][middleIndex] > target)
            {
                rightBound = middleIndex - 1;
            }
            else
            {
                leftBound = middleIndex + 1;
            }
        }

        return false;
    }
};
