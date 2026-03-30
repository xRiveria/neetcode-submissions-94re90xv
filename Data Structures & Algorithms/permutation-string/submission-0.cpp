class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
        {
            return false;
        }

        std::vector<int> valuesS1(26, 0);
        std::vector<int> valuesS2(26, 0);
        for (int i = 0; i < s1.size(); ++i)
        {
            valuesS1[s1[i] - 'a']++;
            valuesS2[s2[i] - 'a']++;
        }

        if (valuesS1 == valuesS2) return true;
        // 3
        // 0 1 2 [3] < Add
        // 3 - 3 = 0 < Remove
        for (int i = s1.size(); i < s2.size(); ++i)
        {
            // Add new character.
            valuesS2[s2[i] - 'a']++;
            // Remove old character;
            valuesS2[s2[i - s1.size()] - 'a']--;
            if (valuesS1 == valuesS2) return true;
        }

        return false;
    }
};
