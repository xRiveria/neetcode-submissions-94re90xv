class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        std::unordered_map<char, int> tHashmap, windowHashmap;
        for (int i = 0; i < t.size(); ++i)
        {
            tHashmap[t[i]]++;
        }

        int l = 0;
        int checkedCharacters = 0;
        int requiredCharacters = tHashmap.size();
        int resultLength = INT_MAX;
        std::pair<int, int> result = {-1, -1};
        for (int r = 0; r < s.length(); ++r)
        {
            char currentChar = s[r];
            windowHashmap[currentChar]++;

            if (tHashmap.count(currentChar) && windowHashmap[currentChar] == tHashmap[currentChar])
            {
                // Character Cleared
                checkedCharacters++;
            }

            // We keep growing the window until all characters are cleared.
            // If all characters were cleared...
            while (checkedCharacters == requiredCharacters)
            {
                // Log the most minimum window size. 
                if ((r - l + 1) < resultLength)
                {
                    resultLength = r - l + 1;
                    result = { l, r };
                }

                // Decrease the window. We do this to see if we can make the minimum string any smaller.
                windowHashmap[s[l]]--;
                if (tHashmap.count(s[l]) && windowHashmap[s[l]] < tHashmap[s[l]])
                {
                    checkedCharacters--;
                }
                l++;
            }
        }

        return resultLength == INT_MAX ? "" : s.substr(result.first, resultLength);
    }
};
