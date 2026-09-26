#include "queen_attack.h"

#include <cstdlib>
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(std::pair<int, int> white,
                         std::pair<int, int> black)
    : white_{white}, black_{black} {

    // Verificar que la posición de la reina blanca esté
    // dentro del tablero 8x8.
    if (white.first < 0 || white.first > 7 ||
        white.second < 0 || white.second > 7) {
        throw std::domain_error("Invalid white queen position");
    }

    // Verificar que la posición de la reina negra esté
    // dentro del tablero 8x8.
    if (black.first < 0 || black.first > 7 ||
        black.second < 0 || black.second > 7) {
        throw std::domain_error("Invalid black queen position");
    }

    // Las dos reinas no pueden ocupar la misma casilla.
    if (white == black) {
        throw std::domain_error("Queens cannot occupy the same position");
    }
}

std::pair<int, int> chess_board::white() const {
    return white_;
}

std::pair<int, int> chess_board::black() const {
    return black_;
}

bool chess_board::can_attack() const {

    // Misma fila
    if (white_.first == black_.first) {
        return true;
    }

    // Misma columna
    if (white_.second == black_.second) {
        return true;
    }

    // Misma diagonal
    if (std::abs(white_.first - black_.first) ==
        std::abs(white_.second - black_.second)) {
        return true;
    }

    return false;
}

} // namespace queen_attack
