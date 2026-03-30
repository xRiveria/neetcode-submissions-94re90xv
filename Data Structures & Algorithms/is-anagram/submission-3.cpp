class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length())
        {
            return false;
        }

        // An alternative way to solve this would be to include unordered_maps.
        // We can populate them both and perform an equality check to solve this as well.
        std::vector<int> values(26, 0); // 26 elements, all initialized to 0.
        // This works fine, as we've ensured that both strings have the same length.
        for (int i = 0; i < s.length(); ++i)
        {
            values[s[i] - 'a']++;
            values[t[i] - 'a']--;
        }

        for (int j = 0; j < values.size(); ++j)
        {
            if (values[j] != 0)
            {
                return false;
            }
        }

        return true;
    }
};
