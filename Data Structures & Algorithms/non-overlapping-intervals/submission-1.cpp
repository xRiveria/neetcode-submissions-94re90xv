class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b)
        {
            return a[0] < b[0];
        });

        // Now sorted by start timings.
        int intervalsRemoved = 0;
        std::vector<std::vector<int>> results;
        
        int i = 0;
        while (i < intervals.size())
        {
            if (results.empty() || results.back()[1] <= intervals[i][0]) // It is fine 
            {
                results.push_back(intervals[i]);
            }
            else
            {
                intervalsRemoved++;
                results.back()[1] = std::min(results.back()[1], intervals[i][1]);
            }

            i++;
        }
    
        return intervalsRemoved; 
    }
};
