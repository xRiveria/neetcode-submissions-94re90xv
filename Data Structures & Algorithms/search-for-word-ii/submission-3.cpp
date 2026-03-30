class TrieNode
{
    public:
        TrieNode* children[26];
        int index; // Index of a word in words if a word ends here. Else, -1.
        int references;

        TrieNode()
        {
            for (int i = 0; i < 26; ++i)
            {
                children[i] = nullptr;
            }
            index = -1;
            references = 0;
        }

        void AddWord(const std::string& word, int i)
        {
            TrieNode* current = this;
            current->references++;
            for (auto c : word)
            {
                int ind = c - 'a';
                if (current->children[ind] == nullptr)
                {
                    current->children[ind] = new TrieNode();
                }
                current = current->children[ind];
                current->references++;
            }
            current->index = i; 
        }
};

class Solution {
public:
    std::vector<std::string> results;
    // Aggresive pruning?
        // Each trie checks something called refs - how many words still pass through this node?
    // When we find a word, we remove it from the Trie.
    // Once a node's refs become 0, the branch is dead. NO oother words use it.
    // So we physically cut the pointer from its parent, prevening future DFS from exploring useless prefixes.
    // And, instead of  using a visite set, we mark the board in place.
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); ++i)
        {
            root->AddWord(words[i], i);
        }

        for (int r = 0; r < board.size(); ++r)
        {
            for (int c = 0; c < board[0].size(); ++c)
            {
                DFS(board, root, r, c, words);
            }
        }

        return results;
    }

    void DFS(auto& board, TrieNode* node, int r, int c, auto& words)
    {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
        {
            return;
        }

        if (board[r][c] == '*') return;
        if (node->children[board[r][c] - 'a'] == nullptr) return;

        char boardChar = board[r][c];
        board[r][c] = '*';
        TrieNode* prev = node;
        node = node->children[boardChar - 'a'];
        // We found the word.
        if (node->index != -1)
        {
            results.push_back(words[node->index]);
            node->index = -1; // Prune cause we found word.
            node->references--;
            if (!node->references) // Becomes 0
            {
                prev->children[boardChar - 'a'] = nullptr; // Prune the branch.
                node = nullptr;
                board[r][c] = boardChar;
                return;
            }
        }

        // Otherwise, explore.
        DFS(board, node, r + 1, c, words);
        DFS(board, node, r, c + 1, words);
        DFS(board, node, r - 1, c, words);
        DFS(board, node, r, c - 1, words);

        board[r][c] = boardChar;
    }
};
