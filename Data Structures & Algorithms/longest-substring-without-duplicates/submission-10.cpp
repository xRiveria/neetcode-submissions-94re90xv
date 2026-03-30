class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxSize = 0;
        std::unordered_map<char, int> values;
        while (r < s.size())
        {
            if (values.count(s[r]))
            {
                int lastSeen = values[s[r]];
                values.erase(s[l]);
                l = std::max(l, lastSeen + 1); // We never move backward. 
            }
            values[s[r]] = r;

            maxSize = std::max(maxSize, r - l + 1);
            r++;
        }

        return maxSize;
    }
};
