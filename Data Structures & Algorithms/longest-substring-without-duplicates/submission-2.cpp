class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> values;
        int longestSubstringLength = 0;
        int leftBound = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (values.find(s[i]) != values.end())
            {
                leftBound = std::max(values[s[i]] + 1, leftBound);
            }

            longestSubstringLength = std::max(longestSubstringLength, i - leftBound + 1);
            values[s[i]] = i;
        }

        return longestSubstringLength;
        /*
        std::unordered_set<char> values;
        int longestSubstringSize = 0;
        int leftPtr = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // If the value continues to exist in our charset, we keep erasing.
            while (values.count(s[i]))
            {   
                values.erase(s[leftPtr]);
                leftPtr++;
            }

            longestSubstringSize = std::max(longestSubstringSize, (i - leftPtr) + 1);
            values.insert(s[i]);
        }

        return longestSubstringSize;
        */
    }
};
