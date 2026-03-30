class Solution {
public:
    string longestPalindrome(string s) {
        int resultLength = 0;
        int resultIndex = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            // Odd Length
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                // Longer
                if (r - l + 1 > resultLength)
                {
                    resultIndex = l;
                    resultLength = r - l + 1;
                }
                l--;
                r++;
            }

            // Even
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                if (r - l + 1 > resultLength)
                {
                    resultIndex = l;
                    resultLength = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(resultIndex, resultLength);
    }
};
