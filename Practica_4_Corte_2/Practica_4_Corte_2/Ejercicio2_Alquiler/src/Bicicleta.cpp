#include "Bicicleta.h"
#include <iostream>
using namespace std;
Bicicleta::Bicicleta(string marca, string modelo, string placa, string tipo)
    : Vehiculo(marca, modelo, placa) {
    this->tipo = tipo;
}
void Bicicleta::mostrarInformacion() {
    cout << "Bicicleta | Marca: " << marca << " | Modelo: " << modelo
         << " | Codigo: " << placa << " | Tipo: " << tipo
         << " | Disponible: " << (disponible ? "Si" : "No") << endl;
}
