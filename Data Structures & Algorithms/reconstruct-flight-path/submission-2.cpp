class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Sort tickets lexicograpphically.
        // Make adjacency list. 
        // Starts from JFK, 
        std::unordered_map<std::string, std::vector<std::string>> adj; // Source to Destination

        // Ensure that tickets are processed in lexicographically smallest order.
        std::sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }

        std::vector<std::string> results = { "JFK" };
        // We want an iterary path, which the airports themselves.
        // This means we want tickets.size() (edge) + 1 answers.
        // 4 Edges -> 5 Airports. We want the 5 airports output as its the itenary. 
        DFS("JFK", results, adj, tickets.size() + 1);
        return results;
    }

    bool DFS(const std::string& src, std::vector<std::string>& res, std::unordered_map<std::string, std::vector<std::string>>& adj, int targetLen)
    {
        if (res.size() == targetLen)
        {
            return true;
        }

        // If this node does not have any destinations, exit.
        if (adj.find(src) == adj.end())
        {
            return false;
        }

        std::vector<std::string> temp = adj[src]; // For all connected nodes...
        for (int i = 0; i < temp.size(); ++i)
        {
            std::string v = temp[i];
            adj[src].erase(adj[src].begin() + i); // Remove this destination.
            res.push_back(v);
            if (DFS(v, res, adj, targetLen)) return true;
            adj[src].insert(adj[src].begin() + i, v);
            res.pop_back();
        }

        return false;

    }
};
