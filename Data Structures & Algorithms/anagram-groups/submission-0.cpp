class Solution {
public:
    // Same anagrams would have the same key!
    // An extremely simple way would be to just performing sorting.
    // Before sorting, we need to save the original state of the words.
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // 1) Create Map: Key to Values
        // 2) For each string in the vector, perform sorting on the string.
        // 3) Map[String].push_back(originalString).
        // 4) For each pair in the map, retrieve the vector (values);
        std::unordered_map<std::string, std::vector<string>> hashMap;
        for (int i = 0; i < strs.size(); ++i)
        {
            std::string stringCopy = strs[i];
            std::sort(stringCopy.begin(), stringCopy.end());
            hashMap[stringCopy].push_back(strs[i]);
        }

        std::vector<std::vector<string>> finalValues;
        for (auto& value : hashMap)
        {
            finalValues.push_back(value.second);
        }

        return finalValues;
    }
};
