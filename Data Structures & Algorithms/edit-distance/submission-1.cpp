class Solution {
public:
    int minChanges = INT_MAX;

    void Compare(string word1, string word2, int currentIndex, int currentTotalChanges)
    {
        // If this path is already worse than (or equal to) the best answer I’ve found so far, stop exploring it. Pruning.at()
        if (currentTotalChanges >= minChanges) 
        {
            return;
        }

        // If both words are fully processed
        if (currentIndex >= word1.size() && currentIndex >= word2.size()) 
        {
            minChanges = min(minChanges, currentTotalChanges);
            return;
        }

        // If word1 ended, need to insert remaining chars from word2
        if (currentIndex >= word1.size())
        {
            minChanges = min(minChanges, currentTotalChanges + (int)word2.size() - currentIndex);
            return;
        }

        // If word2 ended, need to delete remaining chars from word1
        if (currentIndex >= word2.size()) 
        {
            minChanges = min(minChanges, currentTotalChanges + (int)word1.size() - currentIndex);
            return;
        }

        // Characters match, move on
        if (word1[currentIndex] == word2[currentIndex]) 
        {
            Compare(word1, word2, currentIndex + 1, currentTotalChanges);
            return;
        }

        // Delete from word1
        {
            string deleted = word1;
            deleted.erase(currentIndex, 1);
            Compare(deleted, word2, currentIndex, currentTotalChanges + 1);
        }

        // Insert into word1
        {
            string inserted = word1;
            inserted.insert(inserted.begin() + currentIndex, word2[currentIndex]);
            Compare(inserted, word2, currentIndex + 1, currentTotalChanges + 1);
        }

        // Replace in word1
        {
            string replaced = word1;
            replaced[currentIndex] = word2[currentIndex];
            Compare(replaced, word2, currentIndex + 1, currentTotalChanges + 1);
        }
    }

    int minDistance(string word1, string word2) {
        Compare(word1, word2, 0, 0);
        return minChanges;
    }
};