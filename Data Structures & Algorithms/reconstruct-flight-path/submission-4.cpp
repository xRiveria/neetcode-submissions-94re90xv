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
        // 4 Edges -> 5 Airports. We want the 5 airports output as its the itenary, meaning we've used 4 tickets (edges).
        DFS("JFK", results, adj, tickets.size() + 1);
        return results;
    }

    bool DFS(const std::string& src, std::vector<std::string>& res, std::unordered_map<std::string, std::vector<std::string>>& adj, int targetLen)
    {
        if (res.size() == targetLen)
        {
            return true;
        }

        // If the current airport has no outgoing edges in the graph, and you have not completed the itinerary yet, this path fails.
        // Note: most source airports exist because we pre-created them, so this check mostly handles airports that only appear as destinations and never as sources.
        if (adj.find(src) == adj.end())
        {
            return false;
        }

        // Make a copy of the current destination list before iterating. We modify adj[src], so we dont want to modify while iterating.
        std::vector<std::string> temp = adj[src]; // For all connected nodes...
        for (int i = 0; i < temp.size(); ++i)
        {
            // Use the ticket.
            std::string v = temp[i];
            adj[src].erase(adj[src].begin() + i); // Removes that specific edge from the graph, so it cannot be reused.
            // Models “using up” one ticket. Now the itinerary includes that next airport.
            res.push_back(v);
            // Try to complete the itinerary from that airport.
            if (DFS(v, res, adj, targetLen)) return true;
            // If that choice led to a dead end, restore the ticket and remove the airport from the path.
            adj[src].insert(adj[src].begin() + i, v);
            res.pop_back();
        }

        return false;

    }
};
