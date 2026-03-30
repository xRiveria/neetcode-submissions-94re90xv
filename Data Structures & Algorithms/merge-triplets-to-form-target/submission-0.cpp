class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        std::unordered_set<int> good;
        // This question is a little misleading.
        // We can take from any triplet, as long as it gives us a value within the target vector.
        // We simply toss away all triplets that has values bigger than any value in target.
        // And carry on.
        for (const auto& t : triplets) 
        {
            // If a triplet has something bigger than target, you can never undo it.
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) 
            {
                continue;
            }
            for (int i = 0; i < t.size(); i++) 
            {
                // If this triplet matches target at index i, mark that index as "covered".
                if (t[i] == target[i]) 
                {
                    good.insert(i);
                }
            }
        }

        // If all 3 positions (0,1,2) are covered → success.
        return good.size() == 3;
    }
};