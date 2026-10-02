#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

class CryptoSquare {
private:
    string texto;

public:

    CryptoSquare(string mensaje) {

        for (char caracter : mensaje) {

            if (isalnum(caracter)) {
                texto += tolower(caracter);
            }
        }
    }

    string cifrar() {

        int longitud = (int)texto.length();

        int columnas = (int)ceil(sqrt((double)longitud));
        int filas = (int)ceil((double)longitud / columnas);

        string resultado = "";

        for (int columna = 0; columna < columnas; columna++) {

            for (int fila = 0; fila < filas; fila++) {

                int posicion = fila * columnas + columna;

                if (posicion < longitud) {
                    resultado += texto[posicion];
                }
                else {
                    resultado += ' ';
                }
            }

            if (columna < columnas - 1) {
                resultado += ' ';
            }
        }

        return resultado;
    }
};

int main() {

    CryptoSquare mensaje(
        "If man was meant to stay on the ground, "
        "god would have given us roots."
    );

    cout << mensaje.cifrar() << endl;

    return 0;
}