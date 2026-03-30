class Solution {
public:

    string encode(vector<string>& strs) {
        // 1) Delimit the start of each word with a Count and #.
        // We cannot simply use spaces, or random characters as the strings themselves may contain them after all.
        std::string finalString;
        for (auto& aString : strs)
        {
            finalString += std::to_string(aString.length()) + "#" + aString;
        }
        return finalString;
    }

    vector<string> decode(string s) {
        std::vector<string> decodedWords;
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }

            int wordLength = std::stoi(s.substr(i, j - i));
            i = j + 1;
            decodedWords.push_back(s.substr(i, wordLength));
            i += wordLength;
        }

        return decodedWords;
    }
};
