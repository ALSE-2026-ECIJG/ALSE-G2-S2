#include <iostream>
#include "AuthenticationManager.h"

int main() {
    AuthenticationManager am(5);
    am.renew("aaa", 1);
    am.generate("aaa", 2);
    std::cout << "countUnexpiredTokens(6) = " << am.countUnexpiredTokens(6) << " (esperado: 1)\n";
    am.generate("bbb", 7);
    am.renew("aaa", 8);
    am.renew("bbb", 10);
    std::cout << "countUnexpiredTokens(15) = " << am.countUnexpiredTokens(15) << " (esperado: 0)\n";
    return 0;
}
