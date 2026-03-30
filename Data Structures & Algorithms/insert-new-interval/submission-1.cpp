class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int j = intervals.size() - 1;
        int target = newInterval[0]; // Start time of new guy.

        // Get i to a point whereby it sits before newInterval[0] > intervals[mid][0].
        while (i <= j)
        {
            int mid = i + ((j - i) / 2);
            if (intervals[mid][0] < target) // If the start time of the current interval is lesser than the new interval's start...
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        
        intervals.insert(intervals.begin() + i, newInterval);

        std::vector<std::vector<int>> results;
        for (const auto& interval : intervals)
        {
            // As long as the start is greater than the end...
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
