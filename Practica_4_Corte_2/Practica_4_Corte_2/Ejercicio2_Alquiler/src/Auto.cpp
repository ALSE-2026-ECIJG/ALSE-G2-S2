#include "Auto.h"
#include <iostream>
using namespace std;
Auto::Auto(string marca, string modelo, string placa, int capacidad)
    : Vehiculo(marca, modelo, placa) {
    capacidadPasajeros = capacidad;
}
void Auto::mostrarInformacion() {
    cout << "Auto | Marca: " << marca << " | Modelo: " << modelo
         << " | Placa: " << placa << " | Pasajeros: " << capacidadPasajeros
         << " | Disponible: " << (disponible ? "Si" : "No") << endl;
}
