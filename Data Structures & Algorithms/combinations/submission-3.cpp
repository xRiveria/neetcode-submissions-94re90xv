class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> results;
        std::vector<int> combinations(k, 0);
        int i = 0;

        while (i >= 0)
        {
            combinations[i]++; // “At this position, try the next number.” 0, 1, 2, 3 etc.
            // If it’s too big → backtrack
            if (combinations[i] > n) // If combinations[i] went pass n, we subtract i. 
            {
                i--;
                continue;
            }

            if (i == k - 1) // “We are filling the last element of the combination.” So when we set a value here, the combination is complete.
            {
                results.push_back(combinations); // full combination found
            }
            else // (we are not at the last index) Then we still need to fill more positions, so we:
            {
                i++; // Move to the next slot. 
                combinations[i] = combinations[i - 1]; // Initialize the next value:
            }
        }

        return results;
    }
};