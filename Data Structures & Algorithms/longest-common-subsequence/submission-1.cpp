class Solution {
public:
    std::map<std::pair<int, int>, int> vals;
    int SequenceGet(std::string& text1, std::string& text2, int lLength, int rLength)
    {
        if (lLength >= text1.size() || rLength >= text2.size())
        {
            return 0;
        }

        if (vals.count({ lLength, rLength }))
        {
            return vals[{ lLength, rLength }];
        }

        if (text1[lLength] == text2[rLength])
        {
            vals[{ lLength, rLength }] = 1 + SequenceGet(text1, text2, lLength + 1, rLength + 1);
            return vals[{ lLength, rLength }];
        }

        // Otherwise...
        vals[{ lLength, rLength }] = std::max(SequenceGet(text1, text2, lLength + 1, rLength), SequenceGet(text1, text2, lLength, rLength + 1));
        return vals[{ lLength, rLength }];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return SequenceGet(text1, text2, 0, 0);
    }
};
