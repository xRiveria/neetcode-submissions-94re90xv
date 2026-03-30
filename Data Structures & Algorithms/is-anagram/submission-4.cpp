class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        std::vector<int> values(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            values[s[i] - 'a']++;
            values[t[i] - 'a']--;
        }

        for (auto value : values)
        {
            if (value != 0)
            {
                return false;
            }
        }

        return true;
    }
};
