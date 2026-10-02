#include <iostream>
#include <string>
#include <map>

using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    map<string, int> tokens;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (tokens.find(tokenId) != tokens.end()) {
            if (tokens[tokenId] > currentTime) {
                tokens[tokenId] = currentTime + timeToLive;
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int cantidad = 0;

        for (auto token : tokens) {
            if (token.second > currentTime) {
                cantidad++;
            }
        }

        return cantidad;
    }
};

int main() {

    AuthenticationManager authenticationManager(5);

    authenticationManager.generate("aaa", 2);

    cout << "Tokens sin expirar en t=6: "
         << authenticationManager.countUnexpiredTokens(6)
         << endl;

    authenticationManager.generate("bbb", 7);

    authenticationManager.renew("aaa", 8);
    authenticationManager.renew("bbb", 10);

    cout << "Tokens sin expirar en t=15: "
         << authenticationManager.countUnexpiredTokens(15)
         << endl;

    return 0;
}