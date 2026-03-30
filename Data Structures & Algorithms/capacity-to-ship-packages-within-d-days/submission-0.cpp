class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int res = *max_element(weights.begin(), weights.end());
        while (true) {
            int ships = 1, cap = res;
            for (int w : weights) {
                if (cap - w < 0) {
                    ships++;
                    cap = res;
                }
                cap -= w;
            }
            if (ships <= days) {
                return res;
            }
            res++;
        }
    }
};