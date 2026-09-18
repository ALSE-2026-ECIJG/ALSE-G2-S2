#include "armstrong_numbers.h"

namespace armstrong_numbers {

static int contarDigitos(int number) {
    if (number == 0) return 1;
    int contador = 0;
    while (number > 0) {
        contador++;
        number /= 10;
    }
    return contador;
}

bool is_armstrong_number(int number) {
    int numDigitos = contarDigitos(number);
    int suma = 0;
    int copia = number;

    while (copia > 0) {
        int digito = copia % 10;
        int potencia = 1;
        for (int i = 0; i < numDigitos; i++) {
            potencia *= digito;
        }
        suma += potencia;
        copia /= 10;
    }

    return suma == number;
}

}  // namespace armstrong_numbers
