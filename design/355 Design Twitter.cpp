class Twitter {
    using UserId = int;
    using TweetId = int;
    using Time = int;
private:
    int time;
    unordered_map<UserId, vector<pair<TweetId, Time>>> tweets;
    unordered_map<UserId, unordered_set<UserId>> following;
public:
    Twitter():time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        // Assuming there is no duplications
        ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        const auto& userFeed = tweets[userId];
        const auto& followees = following[userId];
        //min heap, keep 10: most recent 10
        auto greater = [](const pair<TweetId, Time>& l, const pair<TweetId, Time>& r){
            return l.second>r.second;
        };
        priority_queue<pair<TweetId, Time>, vector<pair<TweetId, Time>>, decltype(greater)> minHeap(greater);

        auto keepTop = [&minHeap](const pair<TweetId, Time> & tweet){
                if(minHeap.size()<10){
                    minHeap.push(tweet);
                }
                else{
                    Time t = tweet.second;
                    if(t > minHeap.top().second) {
                        minHeap.pop();
                        minHeap.push(tweet);
                    }
                }
        };
        for(const auto& followee : followees){
            const auto& followeeTweets = tweets[followee];
            for(const auto& tweet : followeeTweets){
                keepTop(tweet);
            }
        }
        for(const auto& tweet : userFeed){
            keepTop(tweet);
        }

        vector<TweetId> feed;
        while(!minHeap.empty()){
            feed.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return {feed.rbegin(), feed.rend()};
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            following[followerId].erase(followeeId);
    }
};
