#include "Bicicleta.h"

#include <iostream>

Bicicleta::Bicicleta(const std::string& marca, const std::string& modelo,
                      const std::string& placa, const std::string& tipo)
    : Vehiculo(marca, modelo, placa), tipo_(tipo) {
}

void Bicicleta::mostrarInformacion() const {
    std::cout << "[Bicicleta] " << marca_ << " " << modelo_ << " (Placa: " << placa_ << ") - "
               << "Tipo: " << tipo_ << " - "
               << (disponible_ ? "Disponible" : "Alquilada") << "\n";
}

std::string Bicicleta::getTipo() const {
    return tipo_;
}
