class Solution {
public:
    std::unordered_map<int, std::vector<char>> m_Keys = 
    {
        { 1, { } },
        { 2, { 'a', 'b', 'c' } },
        { 3, { 'd', 'e', 'f' } },
        { 4, { 'g', 'h', 'i' } },
        { 5, { 'j', 'k', 'l' } },
        { 6, { 'm', 'n', 'o' } },
        { 7, { 'p', 'q', 'r', 's' } },
        { 8, { 't', 'u', 'v' } },
        { 9, { 'w', 'x', 'y', 'z' } },
    };
    std::vector<std::string> m_Results;

    void Backtrack(std::string digits, int currentIndex, std::string currentResults)
    {
        if (currentIndex >= digits.size())
        {
            // Success!
            m_Results.push_back(currentResults);
            return;
        }

        // Grab from the current digit's key.
        int d = digits[currentIndex] - '0';
        std::vector<char>& chars = m_Keys[d];
        for (auto c : chars)
        {
            Backtrack(digits, currentIndex + 1, currentResults + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        Backtrack(digits, 0, "");
        return m_Results;        
    }
};
