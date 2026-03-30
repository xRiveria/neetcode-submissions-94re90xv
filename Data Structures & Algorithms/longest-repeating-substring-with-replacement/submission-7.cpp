class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;
        int result = 0;

        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); ++r)
        {
            count[s[r]]++;
            /// maxf = max frequency of any character in the window.
            // If you want to make all characters in the window the same, the best strategy is:
            // Keep the character that appears the most and replace every other character
            // Because replacing fewer characters is always optimal.
            // So the window is valid if (window size) - (most frequent character count) ≤ k
            // maxf always tracks the character that almost the most times.
            maxf = std::max(maxf, count[s[r]]); // 

            // “This condition, using the global maxf, guarantees that there exists some window of this length (possibly earlier) that could be made uniform with ≤ k replacements.”
            while ((r - l + 1) - maxf > k)
            {
                count[s[l]]--;
                l++;
                // We don’t need to recalc maxf exactly when shrinking — using an old, bigger maxf is safe for correctness, and faster.
            }

            result = std::max(result, r - l + 1);
        }

        return result;

        /*
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
        */
    }
};
