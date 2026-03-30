class Solution {
public:
    string longestPalindrome(string s) {
        int longestSubstringLength = 0;
        std::string longestSubstring = "";

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); ++j)
            {
                int l = i;
                int r = j;
                while (l < r && s[l] == s[r])
                {
                    l++;
                    r--;
                }
                
                // Palindrome OKIE
                if (l >= r)
                {
                    std::string subs = s.substr(i, j - i + 1);
                    if (subs.length() > longestSubstringLength)
                    {
                        longestSubstring = subs;
                        longestSubstringLength = subs.length();
                    }
                }
            }
        }

        return longestSubstring;
    }
};
