class Solution {
public:
    std::vector<std::vector<std::string>> m_Results;
    // j = start index of current chunk, i = current end index we are testing
     bool IsPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    /*
        Every position gives you two choices:
        Cut if current substring is palindrome
        Extend and see if a longer palindrome forms 
    */
    void DFS(int j, int i, std::string& s, std::vector<std::string>& currentResults)
    {
        if (i >= s.size())
        {
            if (i == j) // If we've past the end of the usable string and i is also == j, we're done as we've went through the whole string successfully.
            {
                m_Results.push_back(currentResults);
            }

            return;
        }

        // If the current result is a palindrome, cut. Move to the next part of the string.
        // Imagine "aab"
        // This will "a", "a", "b"
        if (IsPalindrome(s, j, i))
        {
            currentResults.push_back(s.substr(j, i - j + 1));
            DFS(i + 1, i + 1, s, currentResults);
            currentResults.pop_back();
        }

        // “Don’t cut yet — maybe a longer palindrome exists.”
        // Maybe "aa (yes)" or "aab (no)"
        DFS(j, i + 1, s, currentResults);
    }

    vector<vector<string>> partition(string s) {
        std::vector<std::string> results;
        DFS(0, 0, s, results);
        return m_Results;
    }
    };
