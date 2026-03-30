class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i)
        {
            int leftBounds = i + 1;
            int rightBounds = numbers.size() - 1;
            int currentTarget = target - numbers[i];

            while (leftBounds <= rightBounds)
            {
                int currentIndex = leftBounds + (rightBounds - leftBounds) / 2;
                if (numbers[currentIndex] == currentTarget)
                {
                    return { i + 1, currentIndex + 1 };
                }
                else if (currentTarget > numbers[currentIndex]) // Value is to the right.
                {
                    leftBounds = currentIndex + 1;
                }
                else // Value is to the right.
                {
                    rightBounds = currentIndex - 1;
                }
            }
        }

        return {};
    }
};
