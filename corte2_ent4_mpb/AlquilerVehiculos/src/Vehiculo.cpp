#include "Vehiculo.h"

Vehiculo::Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa)
    : marca_(marca), modelo_(modelo), placa_(placa), disponible_(true) {
}

std::string Vehiculo::getMarca() const {
    return marca_;
}

std::string Vehiculo::getModelo() const {
    return modelo_;
}

std::string Vehiculo::getPlaca() const {
    return placa_;
}

bool Vehiculo::isDisponible() const {
    return disponible_;
}

void Vehiculo::alquilar() {
    disponible_ = false;
}

void Vehiculo::devolver() {
    disponible_ = true;
}

// Nótese que NO se implementa mostrarInformacion() aquí: es virtual
// pura (= 0 en el .h), así que no tiene cuerpo en la clase base.
