class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananaCount = INT_MIN;
        int minBananaCount = 1;
        for (int i = 0; i < piles.size(); ++i)
        {
            maxBananaCount = std::max(maxBananaCount, piles[i]);
        }

        int i = minBananaCount;
        int j = maxBananaCount;
        int selectedSpeed = maxBananaCount;
        while (i <= j)
        {
            int middleElement = i + ((j - i) / 2); // Sample K. 
            int currentHoursTaken = 0;
            // Try eating.
            for (int i = 0; i < piles.size(); ++i)
            {
                // We have to cast this to a double here.
                // This allows us to have values such as 3.5, which will allow us to ceil it.
                // Otherwise, the decimal portion is dropped.
                currentHoursTaken += std::ceil(static_cast<double>(piles[i]) / middleElement);
            }

            if (currentHoursTaken <= h)
            {
                j = middleElement - 1;
                selectedSpeed = std::min(selectedSpeed, middleElement);
            }
            else
            {
                i = middleElement + 1;
            }
        }

        return selectedSpeed;
    }
};