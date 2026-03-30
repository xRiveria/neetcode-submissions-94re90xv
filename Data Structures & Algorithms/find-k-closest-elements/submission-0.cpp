class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::sort(arr.begin(), arr.end(), [x](int a, int b)
        {
            int aDistance = std::abs(a - x);
            int bDistance = std::abs(b - x);
            if (aDistance != bDistance) return aDistance < bDistance;
            return a < b; // If two elements have the same distance, we prefer the smaller one.
        });

        std::vector<int> results;
        for (int i = 0; i < k; ++i)
        {
            results.push_back(arr[i]);
        }
        std::sort(results.begin(), results.end());
        return results;
    }
};