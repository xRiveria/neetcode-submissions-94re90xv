class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            result += CountPali(s, i, i);
            result += CountPali(s, i, i + 1);
        }

        return result;
    }

    int CountPali(const std::string& s, int start, int end)
    {
        int result = 0;
        while (start >= 0 && end < s.size() && s[start] == s[end])
        {
            result++;
            start--;
            end++;
        }

        return result;
    }
};
