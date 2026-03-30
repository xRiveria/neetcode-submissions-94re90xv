class TimeMap {
public:
    std::unordered_map<string, std::vector<std::pair<int, string>>> values;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // Timestamps are always strictly increasing.
        values[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        string result = "";
        if (values.count(key))
        {
            int l = 0;
            int r = values[key].size() - 1;
            int minIndex = INT_MAX; // Track the closest value.
            while (l <= r)
            {
                int middleIndex = l + ((r - l) / 2);
                if (values[key][middleIndex].first <= timestamp)
                {
                    l = middleIndex + 1;
                    result = values[key][middleIndex].second;
                }
                else
                {
                    r = middleIndex - 1;
                }
            }
        }
        
        return result;
    }
};
