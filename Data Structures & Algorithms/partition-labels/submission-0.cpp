class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::vector<int> values(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            values[s[i] - 'a'] = i;
        }

        std::vector<int> partitionValues;
        int currentEndingIndex = INT_MIN;
        int currentCount = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // See when the current character ends.
            currentEndingIndex = std::max(currentEndingIndex, values[s[i] - 'a']);
            currentCount++;

            if (i == currentEndingIndex)
            {
                partitionValues.push_back(currentCount);
                currentCount = 0;
            }
        }

        return partitionValues;
    }
};
