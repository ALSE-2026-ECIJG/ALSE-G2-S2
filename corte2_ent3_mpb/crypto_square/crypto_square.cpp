#include "crypto_square.h"
#include <cmath>
#include <cctype>

namespace crypto_square {

cipher::cipher(const std::string& input) {
    std::string limpio;
    for (char c : input) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            limpio += std::tolower(static_cast<unsigned char>(c));
        }
    }

    int n = limpio.size();
    if (n == 0) {
        texto_codificado_ = "";
        return;
    }

    int columnas = std::ceil(std::sqrt((double)n));
    int filas = std::ceil((double)n / columnas);
    limpio.resize(filas * columnas, ' ');

    std::string resultado;
    for (int col = 0; col < columnas; col++) {
        for (int fila = 0; fila < filas; fila++) {
            resultado += limpio[fila * columnas + col];
        }
        if (col != columnas - 1) resultado += ' ';
    }

    texto_codificado_ = resultado;
}

std::string cipher::normalized_cipher_text() const {
    return texto_codificado_;
}

}  // namespace crypto_square
