class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b)
        {   
            return a[0] < b[0];
        });
        std::vector<std::vector<int>> results;
        for (auto& interval : intervals)
        {
            if (results.empty() || results.back()[1] < interval[0])
            {
                results.push_back(interval);
            }
            else
            {
                results.back()[1] = std::max(results.back()[1], interval[1]);
            }
        }

        return results;
    }
};
