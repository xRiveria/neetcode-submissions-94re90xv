class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i)
        {
            int tankGasCount = gas[i] - cost[i];
            if (tankGasCount < 0) continue; // We cannot leave the station.
            int j = (i + 1) % n; // Next station.
            while (i != j)
            {
                tankGasCount += gas[j];
                tankGasCount -= cost[j];
                if (tankGasCount < 0) break;
                j = (j + 1) % n;
            }

            if (j == i)
            {
                return i;
            }
        }

        return -1;
    }
};
