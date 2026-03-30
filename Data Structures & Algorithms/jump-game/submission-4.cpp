class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentTarget = nums.size() - 1; // Say index 4 is our goal.
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= currentTarget)
            {
                // If index 3 + jump amount >= index 4. Good. We move the goal post to index 3.
                // Then if index 2 + jump amount >= index 3. Good. We move the goal post to index 2.
                currentTarget = i; // Set new target.
            }
        }

        return currentTarget == 0; // If we reach the start, we can reach the target.
    }
};
