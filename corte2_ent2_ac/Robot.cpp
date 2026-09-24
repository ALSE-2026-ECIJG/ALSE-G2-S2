#include <iostream>
#include <string>

using namespace std;

class Robot {

private:

    int x;
    int y;
    char direccion;

public:

    Robot(int xInicial, int yInicial, char direccionInicial) {

        x = xInicial;
        y = yInicial;
        direccion = direccionInicial;
    }

    void girarDerecha() {

        switch (direccion) {

            case 'N':
                direccion = 'E';
                break;

            case 'E':
                direccion = 'S';
                break;

            case 'S':
                direccion = 'W';
                break;

            case 'W':
                direccion = 'N';
                break;
        }
    }

    void girarIzquierda() {

        switch (direccion) {

            case 'N':
                direccion = 'W';
                break;

            case 'W':
                direccion = 'S';
                break;

            case 'S':
                direccion = 'E';
                break;

            case 'E':
                direccion = 'N';
                break;
        }
    }

    void avanzar() {

        switch (direccion) {

            case 'N':
                y++;
                break;

            case 'S':
                y--;
                break;

            case 'E':
                x++;
                break;

            case 'W':
                x--;
                break;
        }
    }

    void ejecutar(string instrucciones) {

        for (char instruccion : instrucciones) {

            if (instruccion == 'R') {
                girarDerecha();
            }
            else if (instruccion == 'L') {
                girarIzquierda();
            }
            else if (instruccion == 'A') {
                avanzar();
            }
        }
    }
};