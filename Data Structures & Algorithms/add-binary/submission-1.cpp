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
            result += (total % 2) + '0'; // Total can be 0, 1, 2,or 3. So modulo 2 makes it either 0 or 1 if total is either 2 or 3.
            carry = total / 2; // Gives us a carry for our next column. Can be either 0 or 1.

            i--;
            j--;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};