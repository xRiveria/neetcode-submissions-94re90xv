class Solution {
public:
    // Consider this as finding the shortest pathin an unweighted graph.
    // Where each word is a node, and edges connect words that differ by exactly one character.
    // We precompute this adjacencylist by comparing all pairs of words.
    // BFS naturally finds the shortest path as it explores all nodes at distance k before any nodes at distance k + 1.
    
    // Create a mapping from each word to its index in the word list.
    // Build an adjancecy list by comparing all word pairs: connect words tha tidffer by exactly one character.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end() || beginWord == endWord)
        {
            // If the word does not exist in the list, or if beginWord == endWord, return 0.
            // This means 0 transformations were needed to get the result. 
            return 0;
        }

        int n = wordList.size();
        int m = wordList[0].size(); // Size each word.
        std::vector<std::vector<int>> adjList(n);

        // A mapping from each word to its index in the word list.
        std::unordered_map<std::string, int> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[wordList[i]] = i;
        }

        // Compare all word pairs...
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int count = 0;
                for (int k = 0; k < m; ++k)
                {
                    if (wordList[i][k] != wordList[j][k])
                    {
                        count++;
                    }
                }

                // If the words only differ by one letter, add it to the adjacencyList for that word index.
                if (count == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // So now, cat has bat mapped and vice versa. Bag has bat mapped and vice versa. Bag has sag mapped and vice versa.

        // We now have the adjencency list.
        // We now find all words that differ by one character from beginWord and add them to the BFS queue. 
        std::queue<int> q;
        int result = 1; // At least one change.
        std::unordered_set<int> visits;
        for (int i = 0; i < m; ++i) // For all letters in the word...
        {
            for (char c = 'a'; c <= 'z'; c++) // Try to twist each letter and check if that word exists. If the character is the same, continue.
            {
                if (c == beginWord[i])
                {
                    continue;
                }

                std::string word = beginWord.substr(0, i) + c + beginWord.substr(i + 1);
                if (mp.find(word) != mp.end() && visits.find(mp[word]) == visits.end())
                {
                    q.push(mp[word]);
                    // If we've visited this word before, ignore.
                    visits.insert(mp[word]);
                }
            }
        }

        // We now process the queue level by level.
        // This will go through each word until we reach our destined word. 
        while (!q.empty())
        {
            result++;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int node = q.front();
                q.pop();
                if (wordList[node] == endWord)
                {
                    return result; // Word found.
                }
                // Otherwise...
                for (int neh : adjList[node])
                {
                    // If we've visited this word before, ignore.
                    if (visits.find(neh) == visits.end())
                    {
                        visits.insert(neh);
                        q.push(neh);
                    }
                }
            }
        }

        return 0;
    }
};
