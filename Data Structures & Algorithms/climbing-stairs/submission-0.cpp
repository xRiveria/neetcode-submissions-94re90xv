class Solution {
public:
    int totalCount = 0;
    void DFS(int currentSteps, int n)
    {
        if (currentSteps > n)
        {
            return;
        }
        
        if (currentSteps == n)
        {
            totalCount++;
            return;
        }

        DFS(currentSteps + 1, n);
        DFS(currentSteps + 2, n);
    }

    int climbStairs(int n) {
        DFS(0, n);
        return totalCount;
    }
};
