class Solution {
public:
    int m_SubstringCount = 0;

    bool IsPalindrome(const string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void IterateString(const string& s, int start, int end)
    {
        if (end > s.size())
        {
            return;
        }

        if (IsPalindrome(s, start, end - 1))
        {
            m_SubstringCount++;
        }

        IterateString(s, start, end + 1);
    }

    int countSubstrings(string s) {
        m_SubstringCount = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            IterateString(s, i, i + 1);
        }

        return m_SubstringCount;
    }
};