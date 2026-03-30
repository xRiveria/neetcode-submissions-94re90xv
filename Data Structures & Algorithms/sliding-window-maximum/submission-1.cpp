class Solution {
public:
    std::vector<int> results;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       std::priority_queue<std::pair<int, int>> values;
       std::vector<int> results;
       int i = 0;
       while (i < nums.size())
       {
          values.push( { nums[i], i });
          if (i >= k - 1) // Everytime after (k - 1), we need to output values.
          {
            while (values.top().second <= (i - k)) // If the index is outside the window...
            {
                values.pop();
            }
            results.push_back(values.top().first);
          }
          
          i++;
       }

       return results;
    }
};
