class Solution {
public:
    bool canJump(vector<int>& nums) {
        // If i is beyond the farthest place we can jump to, then we got stuck before reaching i.
        int furthestPosition = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
           if (i > furthestPosition)
           {
                return false;
           }
           
           // From index i, we can jump up to nums[i] steps.
           furthestPosition = std::max(furthestPosition, i + nums[i]);

            // We can reach.
           if (furthestPosition >= nums.size() - 1)
           {
            return true;
           }

        }

        // If we never got stuck, it means we could reach every position we visited — therefore we can reach the end.
        return true;
    }
};
