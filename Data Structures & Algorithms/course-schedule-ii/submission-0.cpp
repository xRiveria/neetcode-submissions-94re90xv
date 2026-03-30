class Solution {
public:
    bool DFS(int course, const unordered_map<int, vector<int>>& prerequisites,
             unordered_set<int>& visitedList, unordered_set<int>& cycleCheckList,
             vector<int>& outputs)
    {
        // If we have visited this course before, we have a cycle.
        if (cycleCheckList.count(course))
        {
            return false;
        }

        // If we have visited this node before, just return true.
        if (visitedList.count(course))
        {
            return true;
        }

        // Set that we have already visited this.
        cycleCheckList.insert(course);
        // Check out the prequisites.
        if (prerequisites.count(course))
        {
            for (auto& value : prerequisites.at(course))
            {
                if (!DFS(value, prerequisites, visitedList, cycleCheckList, outputs))
                {
                    return false;
                }
            }
        }

        // All good.
        cycleCheckList.erase(course);
        visitedList.insert(course);
        outputs.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Courses are our nodes.
        // Courses have prerequisites.
        // We simply check if a cycle exists.
        std::unordered_map<int, std::vector<int>> prerequisitesMap;
        for (const auto& itemPair : prerequisites)
        {
            prerequisitesMap[itemPair[0]].push_back(itemPair[1]);
        }

        std::vector<int> outputs;
        std::unordered_set<int> visitingList;
        std::unordered_set<int> cycleCheckList;

        for (int course = 0; course < numCourses; ++course)
        {
            if (!DFS(course, prerequisitesMap, visitingList, cycleCheckList, outputs))
            {
                return {};
            }
        }

        return outputs;

    }
};
