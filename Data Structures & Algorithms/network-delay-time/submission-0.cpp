class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra's Algorithm finds the shortest time from the source node k to all other nodes.
        // It works with both directed/undirected graphs. The only condition is that the edge weights must be positive.
        // The idea is to always expand the node that currently has the smallest known time.
        // Once a node is picked from the minimum heap, its shortest time is final.
        // We use a minimum-heap (priority queue) to always process the closest node next.
        std::unordered_map<int, std::vector<std::pair<int, int>>> edges; // Adjacency list.
        for (const auto& time : times)
        {
            edges[time[0]].emplace_back(time[1], time[2]); // Source, Destination, Time
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
        minHeap.push({ 0, k }); // K is where we still start from, with a cost of 0.

        std::set<int> visitedNodes;
        int t = 0; // Cumulative running counter.
        while (!minHeap.empty())
        {
            auto current = minHeap.top();
            minHeap.pop();
            int time = current.first, node = current.second;
            if (visitedNodes.count(node))
            {
                continue;
            }
            visitedNodes.insert(node);
            t = time;

            // If edges exist from this node...
            if (edges.count(node))
            {
                for (const auto& nextNode : edges[node])
                {
                    int destination = nextNode.first, time2 = nextNode.second;
                    if (!visitedNodes.count(destination))
                    {
                        minHeap.push({ time + time2, destination});
                    }
                }
            }
        }

        return visitedNodes.size() == n ? t : -1;
    }
};
