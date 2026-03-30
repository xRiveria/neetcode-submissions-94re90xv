class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
        for (auto& time : times)
        {
            adj[time[0]].emplace_back(time[1], time[2]);
        }

        std::vector<int> dist(n + 1, INT_MAX);
        DFS(k, 0, adj, dist);

        // After exploring all reachable paths, the answer is the maximum time among all nodes. This includes the last node to receive the signal.
        // If there is a node left that is at infinity, it means we couldnt reach all nodes. Return -1.
        int result = *std::max_element(dist.begin() + 1, dist.end());
        return result == INT_MAX ? -1 : result;
    }

    void DFS(int node, int time, std::unordered_map<int, std::vector<std::pair<int, int>>>& adj, std::vector<int>& dist)
    {
        if (time >= dist[node]) return;
        dist[node] = time; // Update time needed to get to this node. This is updated whenwever we reach a node with a better (smaller) time.
        for (auto& [nei, w] : adj[node]) // For all neighbors...
        {
            DFS(nei, time + w, adj, dist); // Carry on.
        }
    }
};
