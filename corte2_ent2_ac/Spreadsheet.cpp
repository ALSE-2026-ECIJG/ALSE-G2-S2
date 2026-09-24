#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Spreadsheet {

private:

    vector<vector<int>> hoja;

    int obtenerValor(string parte) {

        if (isalpha(parte[0])) {

            int columna = parte[0] - 'A';
            int fila = stoi(parte.substr(1)) - 1;

            return hoja[fila][columna];
        }

        return stoi(parte);
    }

public:

    Spreadsheet(int rows) {

        hoja = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {

        int columna = cell[0] - 'A';
        int fila = stoi(cell.substr(1)) - 1;

        hoja[fila][columna] = value;
    }

    void resetCell(string cell) {

        int columna = cell[0] - 'A';
        int fila = stoi(cell.substr(1)) - 1;

        hoja[fila][columna] = 0;
    }

    int getValue(string formula) {

        int posicion = formula.find('+');

        string izquierda = formula.substr(1, posicion - 1);
        string derecha = formula.substr(posicion + 1);

        int valorIzquierda = obtenerValor(izquierda);
        int valorDerecha = obtenerValor(derecha);

        return valorIzquierda + valorDerecha;
    }
};