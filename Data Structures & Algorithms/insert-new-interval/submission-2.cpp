class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int j = intervals.size() - 1;
        int target = newInterval[0]; // Start time of new guy.

        // Finds the first index i where after the loop, i is the correct insertion index.
        // Everything before i starts earlier than newInterval
        while (i <= j)
        {
            int mid = i + ((j - i) / 2);
            if (intervals[mid][0] < target) // If the start time of the current interval is lesser than the new interval's start, keep going.
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        
        // Now the intervals are still sorted by start time. BUT they may overlap → need merging
        intervals.insert(intervals.begin() + i, newInterval);

        std::vector<std::vector<int>> results;
        for (const auto& interval : intervals)
        {
            // As long as the new start is greater than the previous end, no overlap
            if (results.empty() || results.back()[1] < interval[0])
            {
                results.push_back(interval);
            }
            else
            {
                // Intervals overlap. Merge them by extending the end.
                results.back()[1] = std::max(results.back()[1], interval[1]);
            }
        }

        return results;
    }
};
