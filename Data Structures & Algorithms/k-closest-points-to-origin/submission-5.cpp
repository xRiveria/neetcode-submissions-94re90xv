class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> values;
        // Maintain the top k.
        for (int i = 0; i < points.size(); ++i)
        {
            // Origin 0, 0
            int distance = ((points[i][0] - 0) * (points[i][0] - 0)) + ((points[i][1] - 0) * (points[i][1] - 0));
            values.push({ distance, i});
            if (values.size() > k)
            {
                values.pop();
            }
        }

        std::vector<std::vector<int>> finalResults;
        while (!values.empty())
        {
            finalResults.push_back(points[values.top().second]);
            values.pop();
        }

        return finalResults;
    }
};
