class Solution {
public:
    bool DFS(std::vector<int>& gas, std::vector<int>& cost, int i, int startIndex, int currentGas, int visitedCount)
    {
        int n = gas.size();
        if (visitedCount == n)
        {
            return true; // We visited everything.
        }

        int currentIndex = i % n; // Wrap around. Anything mod with itself is 0. 

        // Remember we start with the gas at the station we're leaving from. 
        // Do we have enough gas to leave the station?
        // If not, kaboom.
        if (currentGas < cost[i])
        {
            return false;
        }

        // Travel to the next station.
        int nextStation = (i + 1) % n;
        // Reduce by the cost needed to leave the current station and top up at the next station.
        int nextGasWeHave = currentGas - cost[i] + gas[nextStation];
        return DFS(gas, cost, nextStation, startIndex, nextGasWeHave, visitedCount + 1); 

    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) 
        {
            // Start at station i with gas[i] in tank
            if (DFS(gas, cost, i, i, gas[i], 0)) 
            {
                return i;
            }
        }
        return -1;
    }
};
