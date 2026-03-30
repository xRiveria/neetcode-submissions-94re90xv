class Solution {
public:
    bool isPalindrome(string s) {
         // Remove non-alphanumeric characters
    s.erase(std::remove_if(s.begin(), s.end(), 
                                        [](char c) { return !std::isalnum(c); }), 
                         s.end());
         std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return std::tolower(c); });                 
        string dupe = s;
        std::reverse(dupe.begin(), dupe.end());
        if (dupe != s)
        {
            return false;
        }

        return true;
    }
};
