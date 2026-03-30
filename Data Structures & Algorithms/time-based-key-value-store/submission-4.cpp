class TimeMap {
public:
    std::map<std::string, std::vector<std::pair<int, std::string>>> cache;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        cache[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        std::vector<std::pair<int, std::string>> secondCache = cache[key];
        int l = 0;
        int r = secondCache.size() - 1;
        std::string result = "";
        while (l <= r)
        {
            int middleIndex = l + ((r - l) / 2);
            if (secondCache[middleIndex].first <= timestamp)
            {
                result = secondCache[middleIndex].second;
                l = middleIndex + 1;
            }
            else
            {
                r = middleIndex - 1;
            }
        }

        return result;
    }
};
