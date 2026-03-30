class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> results;
        int i = 0;
        // Current interval ends before new interval starts → no overlap and hence safe.
        for (i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][1] < newInterval[0])
            {
                results.push_back(intervals[i]);
            }
            else
            {
                break;
            }
        }
        
        // If new interval's end is greater than i's start time.
        while (i < intervals.size() && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        results.push_back(newInterval);

        while (i < intervals.size())
        {
            results.push_back(intervals[i]);
            i++;
        }

        return results;
    }
};
