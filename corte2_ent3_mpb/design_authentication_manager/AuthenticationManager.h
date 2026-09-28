#pragma once
#include <string>
#include <unordered_map>

/**
 * @class AuthenticationManager
 * @brief Administra tokens de autenticacion con tiempo de vida (timeToLive).
 */
class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive);
    void generate(std::string tokenId, int currentTime);
    void renew(std::string tokenId, int currentTime);
    int countUnexpiredTokens(int currentTime);

private:
    int timeToLive_;
    std::unordered_map<std::string, int> expiracion_;
};
