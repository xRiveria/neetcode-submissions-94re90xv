class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;
        // Any triplet that has a value greater than the target at any index cannot be used to form the target.
        for (const auto& t : triplets)
        {
            // For each triplet, you check if it can contribute to one of the 3 positions.
            // If we can independently satisfy all three positions using valid triplets, then merging those triplets will exactly form the target.
            x |= (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]);
            y |= (t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2]);
            z |= (t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2]);
            if (x && y && z) return true;
        }

        return false;
    }
};
