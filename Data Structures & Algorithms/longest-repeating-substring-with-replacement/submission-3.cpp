class Solution {
public:
    int characterReplacement(string s, int k) {
        // The trick to this question is to loop per character.
        // Loop per character!
        int result = 0;
        std::unordered_set<char> values(s.begin(), s.end());

        for (char c : values)
        {
            int count = 0, l = 0;
            for (int r = 0; r < s.size(); ++r)
            {
                if (s[r] == c)
                {
                    count++;
                }

                // If our window size - all our current characters = characters that need replacing is more than k...
                // We shrink our window until this condition becomes false.
                while ((r - l + 1) - count > k)
                {
                    if (s[l] == c)
                    {
                        count--;
                    }
                    l++;
                }


                result = std::max((r - l + 1), result);
            }
        }

        return result;
    }
};
