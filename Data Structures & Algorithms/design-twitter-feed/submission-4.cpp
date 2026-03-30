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

    // Comparator for a Max-Heap based on the first element of a pair
    // For a max-heap sorted by the pair's first element (largest first):
    struct ComparePairs {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a.first < b.first; // Returns true if 'a' has lower priority (should be "smaller" in the heap structure)
        }
    };
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparePairs> pq;
        for (auto& tweet : m_SelfTweets[userId])
        {
            pq.push(tweet);
        }

        for (auto& followGuy : m_FollowList[userId])
        {
            for (auto& guysTweet : m_SelfTweets[followGuy])
            {
                pq.push(guysTweet);
            }
        }

        std::vector<int> finalResults;
        for (int i = 0; i < 10 && !pq.empty(); ++i)
        {
            finalResults.push_back(pq.top().second);
            pq.pop();
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