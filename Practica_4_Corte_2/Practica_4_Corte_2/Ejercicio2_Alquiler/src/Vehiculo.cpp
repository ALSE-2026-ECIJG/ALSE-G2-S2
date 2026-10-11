#include "Vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo(string marca, string modelo, string placa) {
    this->marca = marca;
    this->modelo = modelo;
    this->placa = placa;
    disponible = true;
}
Vehiculo::~Vehiculo() {}
void Vehiculo::mostrarInformacion() {
    cout << "Marca: " << marca << " | Modelo: " << modelo << " | Placa: " << placa
         << " | Disponible: " << (disponible ? "Si" : "No") << endl;
}
string Vehiculo::getPlaca() { return placa; }
bool Vehiculo::estaDisponible() { return disponible; }
void Vehiculo::cambiarDisponibilidad(bool estado) { disponible = estado; }
