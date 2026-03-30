class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Attach original index: tasks[i] = {enqueueTime, processingTime, index}
        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }

        // Sort by enqueueTime, then processingTime, then index (lexicographical)
        sort(tasks.begin(), tasks.end());

        vector<int> results;
        results.reserve(n);

        // Min-heap: {processingTime, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int i = 0;
        long long time = tasks[0][0]; // current time starts at first enqueue

        while (!pq.empty() || i < n) {
            // Push all tasks that have arrived by current time
            while (i < n && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]}); // {processingTime, index}
                ++i;
            }

            if (pq.empty()) {
                // No available tasks: jump time to next task's enqueue time
                time = tasks[i][0];
            } else {
                // Pop task with smallest processing time (tie → smallest index)
                auto [processTime, index] = pq.top();
                pq.pop();

                results.push_back(index);
                time += processTime;
            }
        }

        return results;
    }
};
