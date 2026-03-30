class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end() || beginWord == endWord)
        {
            return 0;
        }

        int result = 0;
        std::queue<std::string> q;
        q.push(beginWord);
        // The goal now is to generate neighbors on the fly.
        // We try replacing each character with all 26 letters.
        // If the resulting word exists in our word set, it is a valid neighbor.
        while (!q.empty())
        {
            result++;
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                std::string node = q.front();
                q.pop();
                if (node == endWord) return result;

                // Generate all possible words by changing one character at a time.
                for (int j = 0; j < node.length(); ++j)
                {
                    char original = node[j];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == original) continue;
                        node[j] = c;
                        // If a generated word is in the word set, add it to the queue and remove it from the set to mark it as visited.
                        if (words.find(node) != words.end())
                        {
                            q.push(node);
                            words.erase(node);
                        }
                    }

                    node[j] = original;
                }
            }
        }

        return 0;
    }
};
