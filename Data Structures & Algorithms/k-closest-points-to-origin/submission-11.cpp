class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> vals;
        std::vector<std::vector<int>> results;
        for (int i = 0; i < points.size(); ++i)
        {
            vals.push({ ((points[i][0] * points[i][0]) + (points[i][1] * points[i][1])), i});
        }
        
        while (k && !vals.empty())
        {
            results.push_back(points[ vals.top().second ]);
            vals.pop();
            k--;
        }

        return results;
    }
};
