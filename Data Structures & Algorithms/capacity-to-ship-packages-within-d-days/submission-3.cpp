class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = 0;
        int maxWeight = INT_MIN;
        for (int i = 0; i < weights.size(); ++i)
        {
            totalWeight += weights[i];
            maxWeight = std::max(maxWeight, weights[i]);
        }

        int bestCapacity = totalWeight; // In the worst case, we will ship everything in a single day.

        // Try every capacity from maxWeight to totalWeight.
        // But we don't have to try every capacity...
        // We can start somewhere in the middle.
        // maxWeight = Left Pointer.
        // totalWeight = Right Pointer.
        while (maxWeight < totalWeight) // We keep shrinking until there is only one number left in our range. If (low == high), this one (and everything above it) works.
        {   
            int currentCapacityPerDay = (totalWeight + maxWeight) / 2;

            int daysNeeded = 1; // Start at a day of 1.
            int weightThusFar = 0;
            for (auto weightItem : weights)
            {
                if (weightThusFar + weightItem > currentCapacityPerDay)
                {
                    daysNeeded++;
                    weightThusFar = 0;
                }
               
                weightThusFar += weightItem;
            }

            // If we can ship everything within the given days, we should try a smaller capacity.
            if (daysNeeded <= days) 
            {
                totalWeight = currentCapacityPerDay;
            }
            else // Else, currentCapacityPerDay is too small. Hence, it must be greater than this.
            { 
                maxWeight = currentCapacityPerDay + 1;
            }
        }

        // Low == High is the minimum capacity that works.
        return maxWeight;
    }
};