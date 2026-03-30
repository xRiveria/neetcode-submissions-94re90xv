/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::vector<int> startTimes;
        std::vector<int> endTimes;
        for (int i = 0; i < intervals.size(); ++i)
        {
            startTimes.push_back(intervals[i].start);
            endTimes.push_back(intervals[i].end);
        }
        std::sort(startTimes.begin(), startTimes.end());
        std::sort(endTimes.begin(), endTimes.end());

        int i = 0;
        int j = 0;
        int roomSize = 0;
        int result = 0;
        while (i < intervals.size()) // If there are remaining meetings that hasn't ended, that is fine as we already allocated rooms for them.
        {
            // This means we need a new room.
            if (startTimes[i] < endTimes[j])
            {
                i++;
                roomSize++;
            }
            else
            {
                // Otherwise, this either means:
                // 1) There is a tie. If there is a tie, a meeting has to end before a new one can proceed.
                // Hence, we increase end pointer and reduce a room size.
                // 2) EndTime < StartTime. This means a meeting ended! We also reduce the room size.
                j++;
                roomSize--;
            }

            result = std::max(result, roomSize);
        }

        return result;
    }
};
