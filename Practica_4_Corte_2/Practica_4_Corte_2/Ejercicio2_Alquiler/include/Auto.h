#ifndef AUTO_H
#define AUTO_H
#include "Vehiculo.h"
class Auto : public Vehiculo {
private:
    int capacidadPasajeros;
public:
    Auto(string marca, string modelo, string placa, int capacidad);
    void mostrarInformacion() override;
};
#endif
