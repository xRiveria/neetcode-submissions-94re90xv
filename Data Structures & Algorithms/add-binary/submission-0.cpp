class Solution {
public:
    string addBinary(string a, string b) {
        std::string result = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int digitA = i >= 0 ? a[i] - '0' : 0;
            int digitB = j >= 0 ? b[j] - '0' : 0;
            int total = digitA + digitB + carry;
            result += (total % 2) + '0';
            carry = total / 2;

            i--;
            j--;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};