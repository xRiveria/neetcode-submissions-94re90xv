class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> values(stones.begin(), stones.end());
        while (true)
        {
            if (values.size() == 1)
            {
                return values.top();
            }
            else if (values.size() == 0)
            {
                return 0;
            }

            int stoneOne = values.top(); values.pop();
            int stoneTwo = values.top(); values.pop();
            if (stoneOne == stoneTwo)
            {
                continue;
            }
            else
            {
                int newWeight = stoneOne - stoneTwo;
                values.push(newWeight);
            }
        }
    }
};
