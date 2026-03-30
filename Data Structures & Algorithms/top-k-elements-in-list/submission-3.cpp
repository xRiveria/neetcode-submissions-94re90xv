class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        std::unordered_map<int ,int> values;
        for (int i = 0; i < nums.size(); ++i)
        {
            values[nums[i]]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        for (auto& value : values)
        {
            minHeap.push({ value.second, value.first });

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        std::vector<int> results;
        for (int i = 0; i < k; ++i)
        {
            results.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return results;

        /*
        std::unordered_map<int, int> values;
        for (int i = 0; i < nums.size(); ++i)
        {
            values[nums[i]]++;
        }
        
        // Place into a vector for sorting. We will sort by the most count of appeared elements.
        std::vector<std::pair<int, int>> valuesArray;
        for (auto& value : values)
        {
            valuesArray.push_back({ value.second, value.first });
        }

        // Sort in ascending order.
        std::sort(valuesArray.rbegin(), valuesArray.rend());

        std::vector<int> results;
        for (int i = 0; i < k; ++i)
        {
            results.push_back(valuesArray[i].second);
        }

        return results;
        */
    }
};
