class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int l = 0;
        int r = 0;

        // r tracks the furthest index we can jump to from l. If at any point we reach or go beyond, we're done.
        // l tracks the index we're jumping from next.
        while (r < nums.size() - 1)
        {
            int furthest = 0;
            // 
            for (int i = l; i <= r; ++i)
            {
                // i + nums[i] means from index i, how far can we jump?
                // We want to jump the furthest we possibly can, so we track this.
                furthest = std::max(furthest, i + nums[i]);
            }

            l = r + 1;
            r = furthest;
            result++;
        }

        return result;
    }
};
