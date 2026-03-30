class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using P = pair<long long,int>; // (distSq, index)
        priority_queue<P> pq;          // max-heap by distSq

        for (int i = 0; i < (int)points.size(); ++i) {
            long long x = points[i][0];
            long long y = points[i][1];
            long long dist = x*x + y*y;

            pq.push({dist, i});
            if ((int)pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        res.reserve(k);
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
