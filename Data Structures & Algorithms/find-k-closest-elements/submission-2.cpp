class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Use binary search to find the leftmost position whereby arr[mid] >= x.
        int l = 0;
        int r = arr.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        // Expand outwards.
        l = l - 1;
        r = l + 1;
        while (r - l - 1 < k)
        {
            if (l < 0)
            {
                r++;
            }
            else if (r >= arr.size())
            {
                l--;
            }
            else if (std::abs(arr[l] - x) <= std::abs(arr[r] - x))
            {
                // Include left side.
                l--;
            }
            else
            {
                r++;
            }
        }
        
        // (exclusive bounds)!
        return std::vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};