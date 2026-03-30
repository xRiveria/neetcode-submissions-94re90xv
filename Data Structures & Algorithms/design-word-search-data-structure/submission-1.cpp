struct Trie
{
    Trie* m_Values[26];
    bool m_IsWord = false;

    Trie()
    {
        for (int i = 0; i < 26; ++i)
        {
            m_Values[i] = nullptr;
        }
        m_IsWord = false;
    }
};

class WordDictionary {
public:
    Trie* m_Root;

    WordDictionary() {
        m_Root = new Trie();
    }
    
    void addWord(string word) {
        Trie* currentNode = m_Root;
        for (char c : word)
        {
            int charIndex = c - 'a';
            if (currentNode->m_Values[charIndex] == nullptr)
            {
                currentNode->m_Values[charIndex] = new Trie();
            }
            currentNode = currentNode->m_Values[charIndex];
        }
        currentNode->m_IsWord = true;
    }
    
    bool search(string word) {
        return DFS(word, 0, m_Root);
    }

    bool DFS(std::string word, int j, Trie* root)
    {
        Trie* currentNode = root;

        for (int i = j; i < word.size(); ++i)
        {
            char c = word[i];
            if (c == '.')
            {
                for (Trie* child : currentNode->m_Values)
                {
                    if (child != nullptr && DFS(word, i + 1, child))
                    {
                        return true;
                    }
                }

                return false;
            }
            else
            {
                if (currentNode->m_Values[c - 'a'] == nullptr)
                {
                    return false;
                }

                currentNode = currentNode->m_Values[c - 'a'];
            }
        }

        return currentNode->m_IsWord;
    }
};
