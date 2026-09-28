#include "AuthenticationManager.h"

AuthenticationManager::AuthenticationManager(int timeToLive) : timeToLive_(timeToLive) {}

void AuthenticationManager::generate(std::string tokenId, int currentTime) {
    expiracion_[tokenId] = currentTime + timeToLive_;
}

void AuthenticationManager::renew(std::string tokenId, int currentTime) {
    auto it = expiracion_.find(tokenId);
    if (it == expiracion_.end() || it->second <= currentTime) {
        return;
    }
    it->second = currentTime + timeToLive_;
}

int AuthenticationManager::countUnexpiredTokens(int currentTime) {
    int contador = 0;
    for (const auto& par : expiracion_) {
        if (par.second > currentTime) contador++;
    }
    return contador;
}
