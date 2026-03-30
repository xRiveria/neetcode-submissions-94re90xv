class Solution {
public:
    int climbStairs(int n) {
        int step1 = 1;
        int step2 = 1;
        for (int i = 0; i < (n - 1); ++i)
        {
            int temp = step1;
            step1 = step1 + step2;
            step2 = temp;
        }

        return step1;
    }
};
