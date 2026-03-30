class Solution {
public:
    std::unordered_map<int, std::vector<int>> preMap;
    std::unordered_set<int> visiting;
    bool DFS(int courseNumber)
    {
        if (visiting.count(courseNumber))
        {
            return false;
        }

        if (preMap[courseNumber].empty())
        {
            return true;
        }

        visiting.insert(courseNumber);
        // Try to clear all its prerequsiites.
        // It repeats. For 0, check 1. For 1, check 2. if 2 has nothing, return true. etc.
        for (auto pre : preMap[courseNumber])
        {
            if (!DFS(pre))
            {
                return false;
            }
        }

        // Once done, clear.
        visiting.erase(courseNumber);
        preMap[courseNumber].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++i)
        {
            preMap[i] = {};
        }

        for (const auto& pre : prerequisites)
        {
            preMap[pre[0]].push_back(pre[1]);
        }

        for (int c = 0; c < numCourses; ++c)
        {
            if (!DFS(c))
            {
                return false;
            }
        }

        return true;
    }
};
