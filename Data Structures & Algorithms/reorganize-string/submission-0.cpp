class Solution {
public:
    // The easiest way to solve this is to create a frequency map.
    // We insert by inserting the character with the most frequency first.
    // We then take this out of the map. And insert the next character.
    // Upon inserting the next character, we then reinsert this previous character.
    // This ensures that we don't have characters side by side that are the same.
    // This greedy approach works because alternating between the two most common characvters maximizes our ability to separate identitical characters.
    // If the heap is empty, but we still have a previous pending character,
    string reorganizeString(string s) {
        std::vector<int> frequencyMap(26, 0);
        for (auto c : s)
        {
            frequencyMap[c - 'a']++;
        }

        std::priority_queue<std::pair<int, char>> maxHeap;
        for (int i = 0; i < 26; ++i)
        {
            if (frequencyMap[i] > 0)
            {
                maxHeap.push({ frequencyMap[i], i + 'a' });
            }
        }

        std::string result;
        std::pair<int, char> previous = { 0, ' ' };
        while (!maxHeap.empty() || previous.first > 0)
        {
            if (maxHeap.empty() && previous.first > 0)
            {
                return ""; 
            }

            auto [count, _char] = maxHeap.top();
            maxHeap.pop();
            result += _char;
            count--;

            if (previous.first > 0)
            {
                maxHeap.push(previous);
            }

            previous = { count, _char };
        }

        return result;
    }
};