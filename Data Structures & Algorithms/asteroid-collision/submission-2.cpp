class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> results;
        std::stack<int> vals;
        for (int i = 0; i < asteroids.size(); ++i)
        {
            while (!vals.empty() && asteroids[i] < 0 && vals.top() > 0) // If the top is positive.
            {
                int result = vals.top() + asteroids[i];
                if (result < 0) vals.pop(); // Our right moving asteroid exploded. asteroids[i] survived. 
                else if (result > 0) asteroids[i] = 0; // The incoming asteroid exploded. Set it to 0 so we don't push it into the stack.
                else // Both are destroyed. Set it to 0 so we don't push it back into the stack.
                {
                    asteroids[i] = 0;
                    vals.pop();
                }
            }
            
            // If the current asteroid survives all collisions, we push it into the stack.
            if (asteroids[i] != 0) vals.push(asteroids[i]);
        }

        while (!vals.empty())
        {
            results.push_back(vals.top()); vals.pop();
        }
        std::reverse(results.begin(), results.end());
        
        return results;
    }
};