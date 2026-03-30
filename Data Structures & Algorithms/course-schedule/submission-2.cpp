class Solution {
public:
    std::unordered_map<int, std::vector<int>> m_PreMap; // Map each course to its prerequisites
    std::unordered_set<int> m_Visiting; // Store all courses along the current DFS path
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Courses are nodes.
        // Prerequisites are edges.
        for (int i = 0; i < numCourses; ++i)
        {
            m_PreMap[i] = {};
        }

        for (const auto& prerequisite : prerequisites)
        {
            m_PreMap[prerequisite[0]].push_back(prerequisite[1]);
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
    
    // Essentially a cycle detection question.
    bool DFS(int c)
    {
        // We run a DFs from each course and try to finish is prerequisite course by recursively traversing
        // through them. To detect a cycle, we initialize a hash set called path, which contains the nodes visited in the current DFS call.
        // If we encounter a course that is already in the path, we can conclude that a cycle is detected.
        if (m_Visiting.count(c))
        {
            return false; // Cycle
        }

        if (m_PreMap[c].empty())
        {
            return true; // My dude has no prerequisites.
        }   

        // For each dependency...
        m_Visiting.insert(c); 
        for (auto pre : m_PreMap[c])
        {
            if (!DFS(pre)) // If we've visited the depedency before, we have a cycle.
            {
                return false;
            }
        }

        // Check complete. All prerequisites valid. 
        m_Visiting.erase(c);
        m_PreMap[c].clear(); // Prequisites cleared!
        return true;
    }
};
