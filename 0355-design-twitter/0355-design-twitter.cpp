class Twitter {
public:
    int time = 0;

    // user -> tweets {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // user -> followed users
    unordered_map<int, unordered_set<int>> following;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // Include user's own tweets
        following[userId].insert(userId);

        for (int followee : following[userId]) {
            auto& list = tweets[followee];

            int start = max(0, (int)list.size() - 10);

            for (int i = start; i < list.size(); i++) {
                pq.push({
                    list[i].first,
                    followee,
                    list[i].second
                });

                if (pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> feed;

        while (!pq.empty()) {
            feed.push_back(get<2>(pq.top()));
            pq.pop();
        }

        reverse(feed.begin(), feed.end());

        return feed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};