// Use a hashmap if there are a mixture of case characters in here.
struct TrieNode
{
    TrieNode* m_Children[26];
    bool m_IsEndOfWord = false;

    TrieNode()
    {
        m_IsEndOfWord = false;
        for (int i = 0; i < 26; ++i)
        {
            m_Children[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    TrieNode* m_Root;

    PrefixTree() {
        m_Root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = m_Root;
        for (char c : word)
        {
            int val = c - 'a';
            if (node->m_Children[val] == nullptr)
            {
                node->m_Children[val] = new TrieNode();
            }
            node = node->m_Children[val];
        }
        node->m_IsEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = m_Root;
        for (char c : word)
        {
            int val = c - 'a';
            if (node->m_Children[val] == nullptr)
            {
                return false;
            }
            node = node->m_Children[val];
        }

        if (node->m_IsEndOfWord)
        {
            return true;
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = m_Root;
        for (char c : prefix)
        {
            int val = c - 'a';
            if (node->m_Children[val] == nullptr)
            {
                return false;
            }
            node = node->m_Children[val];
        }
        
        return true;
    }
};
