class Solution {
public:
    bool DFS(std::vector<int>& values, int index)
    {
        if (index >= values.size())
        {
            return false;
        }

        if (index == values.size() - 1)
        {
            return true;
        }

        for (int i = 1; i <= values[index]; ++i)
        {
            if (DFS(values, index + i))
            {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return DFS(nums, 0);
    }
};
