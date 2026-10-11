#include "SistemaAlquiler.h"

#include <algorithm>
#include <iostream>
#include <utility>

void SistemaAlquiler::registrarVehiculo(std::unique_ptr<Vehiculo> vehiculo) {
    // std::move transfiere la propiedad del unique_ptr hacia el vector;
    // 'vehiculo' (el parámetro local) queda vacío después de esto.
    vehiculos_.push_back(std::move(vehiculo));
}

Vehiculo* SistemaAlquiler::buscarPorPlaca(const std::string& placa) const {
    auto it = std::find_if(vehiculos_.begin(), vehiculos_.end(),
                            [&placa](const std::unique_ptr<Vehiculo>& v) {
                                return v->getPlaca() == placa;
                            });

    if (it == vehiculos_.end()) {
        return nullptr;
    }
    return it->get(); // ->get() obtiene el puntero crudo sin ceder propiedad
}

bool SistemaAlquiler::alquilarVehiculo(const std::string& placa) {
    Vehiculo* vehiculo = buscarPorPlaca(placa);

    if (vehiculo == nullptr) {
        std::cout << "No existe ningún vehículo con placa " << placa << ".\n";
        return false;
    }

    if (!vehiculo->isDisponible()) {
        std::cout << "El vehículo con placa " << placa << " ya está alquilado.\n";
        return false;
    }

    vehiculo->alquilar();
    return true;
}

bool SistemaAlquiler::devolverVehiculo(const std::string& placa) {
    Vehiculo* vehiculo = buscarPorPlaca(placa);

    if (vehiculo == nullptr) {
        std::cout << "No existe ningún vehículo con placa " << placa << ".\n";
        return false;
    }

    vehiculo->devolver();
    return true;
}

void SistemaAlquiler::mostrarDisponibles() const {
    std::cout << "--- Vehículos disponibles ---\n";
    bool hayDisponibles = false;

    for (const auto& vehiculo : vehiculos_) {
        if (vehiculo->isDisponible()) {
            // Llamada polimórfica: según el tipo REAL del objeto
            // apuntado (Auto o Bicicleta), se ejecuta su propia
            // versión de mostrarInformacion().
            vehiculo->mostrarInformacion();
            hayDisponibles = true;
        }
    }

    if (!hayDisponibles) {
        std::cout << "  (No hay vehículos disponibles en este momento)\n";
    }
}

void SistemaAlquiler::mostrarTodos() const {
    std::cout << "--- Todos los vehículos ---\n";

    if (vehiculos_.empty()) {
        std::cout << "  (No hay vehículos registrados)\n";
        return;
    }

    for (const auto& vehiculo : vehiculos_) {
        vehiculo->mostrarInformacion();
    }
}

std::size_t SistemaAlquiler::cantidadVehiculos() const {
    return vehiculos_.size();
}
