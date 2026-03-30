class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
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
    }
};
