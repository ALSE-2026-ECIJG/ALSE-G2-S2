#include <iostream>
#include <cstdlib>
#include "Position.h"

using namespace std;

bool can_attack(Position white, Position black) {

    if (white.row == black.row) {
        return true;
    }

    if (white.column == black.column) {
        return true;
    }

    if (abs(white.column - black.column) ==
        abs(white.row - black.row)) {
        return true;
    }

    return false;
}

int main() {

    Position white = {2, 3};
    Position black = {5, 6};

    if (can_attack(white, black)) {
        cout << "La reina blanca puede atacar a la reina negra."
             << endl;
    }
    else {
        cout << "La reina blanca NO puede atacar a la reina negra."
             << endl;
    }

    return 0;
}
