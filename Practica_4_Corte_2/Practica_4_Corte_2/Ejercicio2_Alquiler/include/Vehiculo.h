#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;
public:
    Vehiculo(string marca, string modelo, string placa);
    virtual ~Vehiculo();
    virtual void mostrarInformacion();
    string getPlaca();
    bool estaDisponible();
    void cambiarDisponibilidad(bool estado);
};
#endif
