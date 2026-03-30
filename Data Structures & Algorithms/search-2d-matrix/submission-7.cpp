class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int leftBound = 0;
        int rightBound = (rows * columns) - 1;

        while (leftBound <= rightBound)
        {
            int middleIndex = leftBound + ((rightBound - leftBound) / 2);
            int currentRow = middleIndex / columns;
            int currentColumn = middleIndex % columns;
            int currentValue = matrix[currentRow][currentColumn];
            if (currentValue == target)
            {
                return true;
            }
            else if (currentValue > target) 
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
