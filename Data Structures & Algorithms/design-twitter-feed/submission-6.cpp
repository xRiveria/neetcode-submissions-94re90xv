class Twitter {
public:
    // Are the tweet IDs ordered in ascending order?
    // By default, priority queue's largest element is at the top.
    std::unordered_map<int, std::vector<std::pair<int, int>>> m_SelfTweets;
    std::unordered_map<int, std::set<int>> m_FollowList;
    int m_Count = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        m_SelfTweets[userId].push_back({ m_Count++, tweetId });
    }

    struct Node {
            int time;
            int tweetID;
            int uid;
            int index; // Index in the user's tweet vector.
        };

    struct ComparePairs {
        bool operator()(const Node& a, const Node& b) const {
            return a.time < b.time; // // b has higher priority if b.first is larger
        }
    };
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<Node, std::vector<Node>, ComparePairs> pq;
        // The key here is to merge these lists together.
        // We maintain a PQ of nodes here.
        // We insert the last element of every node in here. This can be K times if there are are K followees.
        // Since we want 10 elements only, we will grab the top (most recent) element in the list, and add it to the results each time.
        // Each time we insert an entry into the results vector, its element keeps track of remaining items in that user's tweet list.
        // We add the next most recent element in there into the PQ.
        // This way, we always only do n * logN for each getNewsFeed back. 
        auto PushLatest = [&](int uid)
        {
            auto it = m_SelfTweets.find(uid);
            if (it == m_SelfTweets.end()) return;
            auto& v = it->second; // Vector of tweets.
            if (v.empty()) return;
            int i = (int)v.size() - 1; // Index
            pq.push({ v[i].first, v[i].second, uid, i});
        };

        PushLatest(userId); // User itself.
        auto fit = m_FollowList.find(userId);
        if (fit != m_FollowList.end())
        {
            for (int f : fit->second) PushLatest(f);
        }

        // Merge pop up to 10.
        std::vector<int> finalResults;
        while (!pq.empty() && (int)finalResults.size() < 10)
        {
            Node currentNode = pq.top(); pq.pop();
            finalResults.push_back(currentNode.tweetID);

            // Push next older tweet from the same user.
            int nextIndex = currentNode.index - 1;
            auto& v = m_SelfTweets[currentNode.uid];
            if (nextIndex >= 0)
            {
                pq.push({ v[nextIndex].first, v[nextIndex].second, currentNode.uid, nextIndex });
            }
        }

        return finalResults;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        m_FollowList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        m_FollowList[followerId].erase(followeeId);
    }
};