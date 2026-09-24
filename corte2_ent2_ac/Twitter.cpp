#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Twitter {

private:

    map<int, vector<pair<int, int>>> tweets;
    map<int, set<int>> seguidores;

    int tiempo;

public:

    Twitter() {
        tiempo = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({tweetId, tiempo});

        tiempo++;
    }

    vector<int> getNewsFeed(int userId) {

        vector<pair<int, int>> todosLosTweets;

        for (auto tweet : tweets[userId]) {
            todosLosTweets.push_back(tweet);
        }

        for (int usuario : seguidores[userId]) {

            for (auto tweet : tweets[usuario]) {
                todosLosTweets.push_back(tweet);
            }
        }

        sort(todosLosTweets.begin(), todosLosTweets.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 return a.second > b.second;
             });

        vector<int> resultado;

        for (int i = 0; i < todosLosTweets.size() && i < 10; i++) {
            resultado.push_back(todosLosTweets[i].first);
        }

        return resultado;
    }

    void follow(int followerId, int followeeId) {
        seguidores[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        seguidores[followerId].erase(followeeId);
    }
};


int main() {

    Twitter twitter;

    twitter.postTweet(1, 101);
    twitter.postTweet(1, 102);

    twitter.follow(2, 1);

    vector<int> noticias = twitter.getNewsFeed(2);

    cout << "Feed del usuario 2: ";

    for (int tweet : noticias) {
        cout << tweet << " ";
    }

    cout << endl;

    return 0;
}