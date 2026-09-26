#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/**
 * @class Twitter
 * @brief Simplified Twitter supporting posting tweets, follow/unfollow,
 *        and retrieval of the 10 most recent tweets in a user's news feed.
 *
 * Tweets are stored per user with a monotonically increasing timestamp.
 * getNewsFeed() performs a k-way merge (via a max-heap) across the user's
 * own tweet stream and every followed user's stream, in O(k log k) time
 * per extracted tweet, where k = number of contributing users.
 */
class Twitter {
public:
    /**
     * @brief Constructs an empty Twitter object.
     */
    Twitter() : timestamp(0) {

    }
    
    /**
     * @brief Composes a new tweet.
     * @param userId  ID of the user posting the tweet.
     * @param tweetId ID of the tweet (guaranteed unique across all calls).
     */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }
    
    /**
     * @brief Retrieves the 10 most recent tweet IDs in a user's news feed.
     * @param userId ID of the user requesting the news feed.
     * @return Up to 10 tweet IDs, ordered from most recent to least recent.
     */
    vector<int> getNewsFeed(int userId) {
        // One cursor into a single user's tweet log (used as a heap node
        // for the k-way merge).
        struct Entry {
            int timestamp;
            int tweetId;
            int index;                              // position within *source
            const vector<pair<int,int>>* source;    // that user's tweet log

            bool operator<(const Entry& other) const {
                return timestamp < other.timestamp; // max-heap by timestamp
            }
        };

        priority_queue<Entry> heap;

        auto addUser = [&](int uid) {
            auto it = tweets.find(uid);
            if (it != tweets.end() && !it->second.empty()) {
                const auto& log = it->second;
                int lastIdx = (int)log.size() - 1;
                heap.push({log[lastIdx].first, log[lastIdx].second, lastIdx, &log});
            }
        };

        addUser(userId);
        auto followIt = following.find(userId);
        if (followIt != following.end()) {
            for (int followeeId : followIt->second) {
                addUser(followeeId);
            }
        }

        vector<int> result;
        while (!heap.empty() && (int)result.size() < 10) {
            Entry top = heap.top();
            heap.pop();
            result.push_back(top.tweetId);

            if (top.index > 0) {
                int prevIdx = top.index - 1;
                heap.push({(*top.source)[prevIdx].first,
                           (*top.source)[prevIdx].second, prevIdx, top.source});
            }
        }

        return result;
    }
    
    /**
     * @brief Makes followerId start following followeeId.
     * @param followerId ID of the user who will follow someone.
     * @param followeeId ID of the user being followed.
     * @note No-op if followerId == followeeId.
     */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    /**
     * @brief Makes followerId stop following followeeId.
     * @param followerId ID of the user who will unfollow someone.
     * @param followeeId ID of the user being unfollowed.
     */
    void unfollow(int followerId, int followeeId) {
        auto it = following.find(followerId);
        if (it != following.end()) {
            it->second.erase(followeeId);
        }
    }

private:
    int timestamp;                                              ///< Global post-order counter.
    unordered_map<int, unordered_set<int>> following;           ///< userId -> followees.
    unordered_map<int, vector<pair<int,int>>> tweets;           ///< userId -> (timestamp, tweetId), oldest first.
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
