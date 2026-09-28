#pragma once
#include <string>

namespace crypto_square {

class cipher {
public:
    explicit cipher(const std::string& input);
    std::string normalized_cipher_text() const;

private:
    std::string texto_codificado_;
};

}  // namespace crypto_square
