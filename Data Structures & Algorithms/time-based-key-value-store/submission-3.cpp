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
            while (l <= r)
            {
                int middleIndex = l + ((r - l) / 2);
                // Implies that the current value is lesser than the wanted timestamp.
                // It may not be exact, but it fulfills the condition whereby previousTimestap <= timestamp.
                // We will save it. This is guaranteed to be the closest to the wanted timestamp.
                // Because when we do middleIndex + 1, we edge closer to the target (hence finding a closer minimum) and the above loop repeats.
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
