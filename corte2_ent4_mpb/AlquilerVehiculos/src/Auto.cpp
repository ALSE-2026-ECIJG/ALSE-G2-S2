#include "Auto.h"

#include <iostream>

Auto::Auto(const std::string& marca, const std::string& modelo, const std::string& placa,
           int capacidadPasajeros)
    : Vehiculo(marca, modelo, placa), capacidadPasajeros_(capacidadPasajeros) {
    // Vehiculo(marca, modelo, placa) llama primero al constructor de la
    // clase base: así marca_, modelo_, placa_ y disponible_ quedan
    // inicializados antes de que Auto agregue lo suyo.
}

void Auto::mostrarInformacion() const {
    std::cout << "[Auto] " << marca_ << " " << modelo_ << " (Placa: " << placa_ << ") - "
               << "Capacidad: " << capacidadPasajeros_ << " pasajeros - "
               << (disponible_ ? "Disponible" : "Alquilado") << "\n";
}

int Auto::getCapacidadPasajeros() const {
    return capacidadPasajeros_;
}
