#include "SistemaAlquiler.h"
#include <iostream>
using namespace std;

SistemaAlquiler::~SistemaAlquiler() {
    for (Vehiculo* vehiculo : vehiculos) delete vehiculo;
}
void SistemaAlquiler::registrarVehiculo(Vehiculo* vehiculo) {
    vehiculos.push_back(vehiculo);
    cout << "Vehiculo registrado.\n";
}
void SistemaAlquiler::alquilar(string placa) {
    for (Vehiculo* v : vehiculos) {
        if (v->getPlaca() == placa && v->estaDisponible()) {
            v->cambiarDisponibilidad(false);
            cout << "Alquiler realizado.\n";
            return;
        }
    }
    cout << "Vehiculo no encontrado o no disponible.\n";
}
void SistemaAlquiler::devolver(string placa) {
    for (Vehiculo* v : vehiculos) {
        if (v->getPlaca() == placa && !v->estaDisponible()) {
            v->cambiarDisponibilidad(true);
            cout << "Vehiculo devuelto.\n";
            return;
        }
    }
    cout << "No se encontro un alquiler para ese codigo.\n";
}
void SistemaAlquiler::mostrarDisponibles() {
    bool hay = false;
    for (Vehiculo* v : vehiculos) {
        if (v->estaDisponible()) {
            v->mostrarInformacion();
            hay = true;
        }
    }
    if (!hay) cout << "No hay vehiculos disponibles.\n";
}
