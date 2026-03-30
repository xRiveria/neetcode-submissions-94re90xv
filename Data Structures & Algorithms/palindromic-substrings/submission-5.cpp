class Solution {
public:
    int m_SubstringCount = 0;

    void IterateString(const string& s, int start, int len)
    {
        if (start + len > s.size())
        {
            return;
        }

        string subString = s.substr(start, len);
        string secondString = subString;
        reverse(secondString.begin(), secondString.end());

        if (subString == secondString)
        {
            m_SubstringCount++;
        }

        IterateString(s, start, len + 1);
    }

    int countSubstrings(string s) {
        m_SubstringCount = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            IterateString(s, i, 1);
        }

        return m_SubstringCount;
    }
};