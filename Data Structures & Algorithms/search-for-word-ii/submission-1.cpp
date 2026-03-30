class TrieNode {
    public:
        // For example, all words that start with A.
        // All words that start with B, etc.
        std::unordered_map<char, TrieNode*> children;
        bool isWord;

        TrieNode() : isWord(false) { }

        void AddWord(const std::string& word)
        {
            TrieNode* current = this;
            for (char c : word)
            {
                if (!current->children.count(c))
                {
                    current->children[c] = new TrieNode();
                }

                current = current->children[c];
            }

            current->isWord = true;
        }
};

class Solution {
public:
    std::unordered_set<std::string> results;
    std::vector<std::vector<bool>> visited;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* rootNode = new TrieNode();
        for (const std::string& word : words)
        {
            rootNode->AddWord(word);
        }

        int rows = board.size();
        int column = board[0].size();
        visited.assign(rows, std::vector<bool>(column, false));

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < column; ++c)
            {
                DFS(board, r, c, rootNode, "");
            }
        }

        return std::vector<std::string>(results.begin(), results.end());
    }

    void DFS(std::vector<std::vector<char>>& board, int r, int c, TrieNode* node, std::string word)
    {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
        {
            return;
        }

        // If visited before, or the current character doesn't exist in the list, we ignore.
        if (visited[r][c] || !node->children.count(board[r][c]))
        {
            return;
        }

        visited[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord)
        {
            results.insert(word);
        }

        DFS(board, r + 1, c, node, word);
        DFS(board, r, c + 1, node, word);
        DFS(board, r - 1, c, node, word);
        DFS(board, r, c - 1, node, word);

        visited[r][c] = false;
    }
};
