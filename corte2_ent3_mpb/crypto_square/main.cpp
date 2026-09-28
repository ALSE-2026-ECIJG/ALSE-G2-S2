#include <iostream>
#include "crypto_square.h"

int main() {
    crypto_square::cipher c("If man was meant to stay on the ground, god would have given us roots.");
    std::cout << c.normalized_cipher_text() << "\n";
    return 0;
}
