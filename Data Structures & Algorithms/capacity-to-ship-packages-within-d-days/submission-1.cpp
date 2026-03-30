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
        for (int currentCapacityPerDay = maxWeight; currentCapacityPerDay <= totalWeight; ++currentCapacityPerDay)
        {   
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

            // If we can ship everything within the given days...
            if (daysNeeded <= days) 
            {
                // Since we are starting at the smallest possible capacity, the moment we find a valid one, we can return.
                // This is because the capacity is already at maxWeight. The moment there is a valid one, everything after is also valid.
                bestCapacity = currentCapacityPerDay;
                break; 
            }
        }

        return bestCapacity;
    }
};