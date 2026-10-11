#ifndef BICICLETA_H
#define BICICLETA_H
#include "Vehiculo.h"
class Bicicleta : public Vehiculo {
private:
    string tipo;
public:
    Bicicleta(string marca, string modelo, string placa, string tipo);
    void mostrarInformacion() override;
};
#endif
