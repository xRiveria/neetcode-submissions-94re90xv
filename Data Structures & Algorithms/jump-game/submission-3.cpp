class Solution {
public:
    std::unordered_map<int, bool> dfs;
    bool DFS(std::vector<int>& values, int index)
    {
        if (index >= values.size())
        {
            return false;
        }

        if (dfs.count(index))
        {
            return dfs[index];
        }

        if (index == values.size() - 1)
        {
            return true;
        }

        for (int i = 1; i <= values[index]; ++i)
        {
            if (DFS(values, index + i))
            {
                dfs[index + i] = true;
                return true;
            }
            else
            {
                dfs[index + i] = false;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return DFS(nums, 0);
    }
};
