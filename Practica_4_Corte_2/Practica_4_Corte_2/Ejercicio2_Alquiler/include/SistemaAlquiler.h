#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H
#include <vector>
#include "Vehiculo.h"
using namespace std;
class SistemaAlquiler {
private:
    vector<Vehiculo*> vehiculos;
public:
    ~SistemaAlquiler();
    void registrarVehiculo(Vehiculo* vehiculo);
    void alquilar(string placa);
    void devolver(string placa);
    void mostrarDisponibles();
};
#endif
