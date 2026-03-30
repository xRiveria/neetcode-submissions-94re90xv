class Solution {
public:
    bool isPalindrome(string s) {
        // Ignore non-alphanumeric characters.
        // We will use a definite 2 pointer approach here.
        if (s.length() == 1)
        {
            return true;
        }

        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            while (i < j && !std::isalnum(s[i]))
            {
                i++;
            }

            while (i < j && !std::isalnum(s[j]))
            {
                j--;
            }

            if (std::tolower(s[i]) == std::tolower(s[j]))
            {
                i++;
                j--;
                continue;
            }

            return false;
        }

        return true;
    }
};
