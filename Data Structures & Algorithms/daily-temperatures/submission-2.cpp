class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> proxyTemps;
        std::vector<int> finalResults(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i)
        {
            int currentTemperature = temperatures[i];
            while (!proxyTemps.empty() && currentTemperature > proxyTemps.top().first)
            {
                auto currentPair = proxyTemps.top();
                int positionDiff = i - currentPair.second;
                proxyTemps.pop();
                finalResults[currentPair.second] = positionDiff;
            }
            proxyTemps.push({ temperatures[i], i });
        }

        return finalResults;

        /*
        int i = 0;
        int j = i + 1;
        std::vector<int> results(temperatures.size());
        while (i < temperatures.size())
        {
            while (i < temperatures.size() && j < temperatures.size() && temperatures[j] <= temperatures[i])
            {
                j++;
            }

            if (j < temperatures.size())
            {
                results[i] = j - i;
                i++;
                j = i + 1;
            }
            else
            {
                results[i] = 0;
                i++;
                j = i + 1;
            }
        }

        return results;
        */
    }
};
