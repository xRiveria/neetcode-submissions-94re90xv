class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        for (int i = 0; i < position.size(); ++i)
        {
            cars.push_back({ position[i], speed[i] });
        }
        std::sort(cars.begin(), cars.end());

        std::vector<float> fleets;
        for (int i = cars.size() - 1; i >= 0; --i)
        {
            float timeTaken = (float)(target - cars[i].first) / cars[i].second;
            fleets.push_back(timeTaken);

            if (fleets.size() >= 2 && fleets.back() <= fleets[fleets.size() - 2])
            {
                // Means we're going to catch up with the dude in front.
                fleets.pop_back();
            }
        }

        return fleets.size();
    }
};
