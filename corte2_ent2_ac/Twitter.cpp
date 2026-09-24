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

        // Tweets del mismo usuario
        for (auto tweet : tweets[userId]) {
            todosLosTweets.push_back(tweet);
        }

        // Tweets de los usuarios que sigue
        for (int usuario : seguidores[userId]) {

            for (auto tweet : tweets[usuario]) {
                todosLosTweets.push_back(tweet);
            }
        }

        // Ordenar del más reciente al más antiguo
        sort(todosLosTweets.begin(), todosLosTweets.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 return a.second > b.second;
             });

        vector<int> resultado;

        // Guardar máximo 10 tweets
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