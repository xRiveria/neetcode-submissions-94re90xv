class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int n = nums.size();
       std::vector<int> output(n - k + 1);
       std::deque<int> q; // Store indices of elements in decreasing order of their values.
       // The front of the deque alwas holds the index of the current window's mazimum.
       // Smaller elements behind a bigger one are useless as they can never become ther max later.
       // Hence, we remove them when pushing a new number.
       // If the element at the front falls out the window, we remove it. 
       int l = 0, r = 0;

       while (r < n)
       {
        // Remove indices whose values are smaller than the new value as these cannot be future maximums.
        while (!q.empty() && nums[q.back()] < nums[r])
        {
            q.pop_back();
        }
        // Add the new index to the deque.
        q.push_back(r);

        // If the left pointer passes the front index, remove it (front index) as is outside the window.
        if (l > q.front())
        {
            q.pop_front();
        }

        // Once the window reaches size k, the front of the deque represents the maximum. We add it to the output.
        if ((r + 1) >= k)
        {
            output[l] = nums[q.front()];
            l++;
        }
        // Expand window.
        r++;
       
    }

    return output;
    }
};
