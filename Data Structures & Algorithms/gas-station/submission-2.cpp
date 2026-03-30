class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // If the total gas avaliable is less than the total gas required, there is no way to complete the circuit from any station.
        // If it is sufficient, then there must be a valid starting station.
        if (std::accumulate(gas.begin(), gas.end(), 0) < std::accumulate(cost.begin(), cost.end(), 0))
        {
            return -1;
        }

        int totalGas = 0;
        int startingIndexCandidate = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            // Earlier, we checked: if (total gas < total cost) return -1.
            // So across the entire circle: sum(all stations) ≥ 0. That means that even if some parts of the trip are bad, the whole loop gives at least as much gas as it costs.
            // This means we're destined to complete the entire trip.
            // If the total gas from S to i is negative, then starting anywhere between S and i gives you even less gas — so you also fail.
            // After the last reset, suppose the algorithm ends with: start = K.
            // We know: every segment we skipped before K had negative total, so we were right to skip them.
            // from K to the end of the array and then wrapping back to K, the total sum is non-negative.
            // Because the total sum of the whole trip is ≥ 0, once you start at K you never “inherit” any negative debt from earlier bad segments — you begin fresh right after all the negative parts are done.
            totalGas += (gas[i] - cost[i]);
            if (totalGas < 0)
            {
                totalGas = 0;
                startingIndexCandidate = i + 1;
            }
        }

        return startingIndexCandidate;

        // Some stretches of the circle are “gas-losing” segments. If we try starting before such a segment, we fail — and any start inside it also fails.
        // We keep jumping forward until we’re right after the last “bad” segment.
        // Since total gas ≥ total cost, everything from there onward balances out — and that start works.
    }
};
