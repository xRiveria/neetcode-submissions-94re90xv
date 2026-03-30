class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), node = 0;
        std::vector<int> dist(n, INT_MAX);
        std::vector<bool> visit(n, false);
        int edges = 0, result = 0;

        while (edges < n - 1)
        {
            visit[node] = true;
            int nextNode = -1;
            for (int i = 0; i < n; ++i)
            {
                if (visit[i]) continue;
                int currentDistance = std::abs(points[i][0] - points[node][0]) + 
                                      std::abs(points[i][1] - points[node][1]);
                dist[i] = std::min(dist[i], currentDistance);
                if (nextNode == -1 || dist[i] < dist[nextNode])
                {
                    nextNode = i;
                }
            }
            result += dist[nextNode];
            node = nextNode;
            edges++;
        }
        
        return result;
    }
};
