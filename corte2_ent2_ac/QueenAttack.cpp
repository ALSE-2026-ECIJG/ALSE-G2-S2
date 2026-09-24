#include <cstdlib>
#include "Position.h"

bool can_attack(Position white, Position black) {

    // Misma fila
    if (white.row == black.row) {
        return true;
    }

    // Misma columna
    if (white.column == black.column) {
        return true;
    }

    // Misma diagonal
    if (abs(white.column - black.column) ==
        abs(white.row - black.row)) {
        return true;
    }

    return false;
}