class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxSize = 0;
        std::unordered_set<char> values;
        while (r < s.size())
        {
            while (values.count(s[r]))
            {
                values.erase(s[l]);
                l++;
            }
            values.insert(s[r]);

            maxSize = std::max(maxSize, r - l + 1);
            r++;
        }

        return maxSize;
    }
};
