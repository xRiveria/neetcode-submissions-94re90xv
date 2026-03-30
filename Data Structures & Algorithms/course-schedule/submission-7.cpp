class Solution {
public:
    std::unordered_map<int, std::vector<int>> preMap;
    std::set<int> visiting;
    bool DFS(int course)
    {  
        // Cycle
        if (visiting.count(course))
        {
            return false;
        }

        // No Prerequisites
        if (preMap[course].empty())
        {
            return true;
        }

        visiting.insert(course);
        for (auto& preq : preMap[course])
        {
            if (!DFS(preq))
            {
                return false;
            }
        }

        visiting.erase(course); // Mark as done visting. 
        preMap[course].clear(); // Mark the course's prequisites as done. 
        return true; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (const auto& preReq : prerequisites)
        {
            preMap[preReq[0]].push_back(preReq[1]);
        }
        
        // Try to finish the set of courses. 
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
