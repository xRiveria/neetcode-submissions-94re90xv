class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> frequencyMap(26, 0);
        for (int i = 0; i < tasks.size(); ++i)
        {
            frequencyMap[tasks[i] - 'A']++;
        }

        // Stores tasks that are ready to run, ordered by highest remaining frequency.
        std::priority_queue<int> maxHeap;
        for (auto& frequency : frequencyMap)
        {
            if (frequency > 0)
            {
                maxHeap.push(frequency);
            }
        }

        // At every time unit, you either run a task, or wait (idle) until the next task becomes available.
        int time = 0;
        // Stores tasks that are cooling down and cannot be run yet.
        // Each element is { remainingCount, availableTime }.
        std::queue<std::pair<int, int>> aQueue;
        while (!maxHeap.empty() || !aQueue.empty())
        {
            time++;
            // If the heap is empty, we update time to match the next avaliable task in the queue, covering idle time.
            // Remember we can only process 1 item for CPU time. This avoids counting idle cycles one-by-one
            if (maxHeap.empty())
            {
                time = aQueue.front().second;
            }
            else
            {
                // Process the most frequent task from the heap.
                int count = maxHeap.top() - 1; // Decrease the frequency.
                maxHeap.pop();
                if (count > 0) // If there are more frequencies left...
                {
                    // Add back to the queue. This means we can only process the next element at cycle (time + n).
                    aQueue.push({ count, time + n });
                }
            }

            // If the task at the front of the queue becomes avaliable, we pop it and reinsert into the heap.
            // This means we process it at the next cycle, after the cooldown is over.
            if (!aQueue.empty() && aQueue.front().second == time)
            {
                maxHeap.push(aQueue.front().first);
                aQueue.pop();
            }
        }

        return time;
    }
};
