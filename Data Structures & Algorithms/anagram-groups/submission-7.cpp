class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // The key here is to know that we can use hashmaps keys to identify the vectors.
        // In this optimized solution, we want to avoid the sorting.
        // We can do that through the classic (c - 'a') method.
        std::unordered_map<string, std::vector<string>> hashMap;
        for (int i = 0; i < strs.size(); ++i)
        {
            std::vector<int> values(26, 0);
            for (char c : strs[i])
            {
                values[c - 'a']++;
            }
            
            std::string uniqueString = "";
            for (int j = 0; j < values.size(); ++j)
            {
                // Imagine we have abbbbbbbbbbbb and aaaaaaaaaaab.
                // If we simply add their frequenties together into a string...
                // We get 1 11. We have 11 1 for the second, which looks similar 111 and 111.
                // To uniquefy this, we form 1#11 and 11#1, this makes it unique. 
                uniqueString += std::to_string(values[j]) + "#";
            }

            hashMap[uniqueString].push_back(strs[i]);
        }

        std::vector<std::vector<string>> finalValues;
        for (const auto& value : hashMap)
        {
            finalValues.push_back(value.second);
        }

        return finalValues;
    }

/*      // Same anagrams would have the same key!
        // An extremely simple way would be to just performing sorting.
        // Before sorting, we need to save the original state of the words.
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
*/
};
