class Solution {
public:
    bool DFS(int course, std::vector<std::vector<int>>& pre, std::unordered_set<int>& visited, std::unordered_set<int>& cycle, std::vector<int>& output)
    {
        if (cycle.count(course))
        {
            return false; // Cycle detected.
        }

        // If this course is already fully processed (all prerequisites cleared), add.
        if (visited.count(course))
        {
            return true;
        }

        cycle.insert(course);
        for (int i = 0; i < pre[course].size(); ++i)
        {
            if (!DFS(pre[course][i], pre, visited, cycle, output))
            {
                return false;
            }
        }

        // Course processed.
        cycle.erase(course); // Purge from cycle list.
        visited.insert(course);
        output.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> pre(numCourses);
        for (auto c : prerequisites)
        {
            pre[c[0]].push_back(c[1]);
        }

        std::vector<int> output;
        std::unordered_set<int> visited; //  tracks fully processed courses
        std::unordered_set<int> cycle; // tracks the current DFS path (for cycle detection)
        for (int i = 0; i < numCourses; ++i)
        {
            if (!DFS(i, pre, visited, cycle, output))
            {
                return {};
            }
        }

        return output;
    }
};
