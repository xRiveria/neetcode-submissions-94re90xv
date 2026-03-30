class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // Odd Length
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                result++;
                l--;
                r++;
            }

            // Even Length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                result++;
                l--;
                r++;
            }
        }

        return result;
    }
};
