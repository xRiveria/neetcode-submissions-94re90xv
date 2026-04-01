class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Time.
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> poop;
        
        std::set<int> visitedNodes;
        std::unordered_map<int, std::vector<std::pair<int, int>>> edges; // adj list.
        for (const auto& time : times)
        {
            edges[time[0]].push_back({ time[1], time[2] });
        }

        poop.push({ 0, k });
        
        int t = 0;

        while (!poop.empty())
        {
            if (visitedNodes.size() == n)
            {
                break;
            }

            std::pair<int, int> f = poop.top();
            poop.pop();

            if (visitedNodes.count(f.second)) continue; // Possible if there are items in the queue unvisited yet and we push more.

            visitedNodes.insert(f.second);
            t = std::max(t, f.first);

            for (auto& nei : edges[f.second])
            {
                if (!visitedNodes.count(nei.first))
                {
                    poop.push({ f.first + nei.second, nei.first });
                }
            }

            
        }

        if (visitedNodes.size() == n) return t;
        return -1; 
    }
};
