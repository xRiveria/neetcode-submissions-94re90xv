class Solution {
public:
    // We want to add all words that differ by one character from one another into an adjacencyList.
    // Then, we check beginWord itself.
    // We then try to permutate beginWord character by character.
    // If the resulting word exists in the wordList, we add it to the queue.
    // We now go through the queue. It should be all words that differ by one character from beginWord.
    // We now chase down all words that differ by one character from the above.
    // We make sure to process all words a level first.
    // We use a visitedList to avoid checking the same words again. 
    // Once we find the word, we end. 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Use wildcards to group words.
        if (endWord.empty() || std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }

        std::unordered_map<std::string, std::vector<std::string>> neighbors;
        // For each word in the list including beginWord, generate patterns by replacing each character
        // with * and group words by these patterns.
        wordList.push_back(beginWord);
        for (const std::string& word : wordList)
        {
            for (int j = 0; j < word.size(); ++j)
            {
                std::string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                neighbors[pattern].push_back(word);
            }
        }
        // This means for a word pika, we get patterns *ika, p*ka, pi*a, pik*.
        // And we do this for every word in the list.
        // If there is a word bika, it gets thrown in the same pattern bucket as *ika. 

        std::unordered_set<std::string> visitedList{ beginWord };
        std::queue<std::string> q;
        q.push(beginWord);
        int result = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                std::string word = q.front();
                q.pop();
                if (word == endWord) return result;

                for (int j = 0; j < word.size(); ++j)
                {
                    std::string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    // Grab all words in the pattern bucket and throw it in.
                    // So for Pika, we get everything that matches *ika and toss it in.
                    // So this is one change for the first character *.
                    // Then, we continue with p*ka, and then pi*a until we have done enough changes to meet our target word.
                    for (const std::string& neiWord : neighbors[pattern])
                    {
                        if (visitedList.find(neiWord) == visitedList.end())
                        {
                            visitedList.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }

            ++result;
        }

        return 0;
    }
};
