/**
 * @file main.cpp
 * @brief Programa de demostración del sistema de alquiler de vehículos.
 */

#include <iostream>
#include <memory>

#include "Auto.h"
#include "Bicicleta.h"
#include "SistemaAlquiler.h"

int main() {
    SistemaAlquiler sistema;

    // 1) Registrar vehículos de distintos tipos.
    //    std::make_unique crea el objeto y lo envuelve en un
    //    unique_ptr<Auto> (o Bicicleta), que se convierte implícitamente
    //    a unique_ptr<Vehiculo> al pasarlo a registrarVehiculo.
    sistema.registrarVehiculo(std::make_unique<Auto>("Mazda", "CX-5", "ABC123", 5));
    sistema.registrarVehiculo(std::make_unique<Auto>("Renault", "Logan", "DEF456", 4));
    sistema.registrarVehiculo(std::make_unique<Bicicleta>("Trek", "Marlin 7", "BIC001", "montaña"));
    sistema.registrarVehiculo(std::make_unique<Bicicleta>("Giant", "Escape 3", "BIC002", "urbana"));

    std::cout << "Vehículos registrados: " << sistema.cantidadVehiculos() << "\n\n";

    // 2) Mostrar todos: aquí se ve el polimorfismo -- cada vehículo se
    //    imprime con SU PROPIO formato (Auto muestra capacidad de
    //    pasajeros, Bicicleta muestra su tipo), aunque el sistema los
    //    trata a todos simplemente como "Vehiculo*".
    sistema.mostrarTodos();

    // 3) Alquilar un vehículo.
    std::cout << "\nAlquilando el auto ABC123...\n";
    sistema.alquilarVehiculo("ABC123");

    // 4) Intentar alquilar el mismo vehículo de nuevo (debe fallar).
    std::cout << "\nIntentando alquilar ABC123 de nuevo...\n";
    sistema.alquilarVehiculo("ABC123");

    // 5) Intentar alquilar una placa que no existe.
    std::cout << "\nIntentando alquilar una placa inexistente (ZZZ999)...\n";
    sistema.alquilarVehiculo("ZZZ999");

    std::cout << "\n";
    sistema.mostrarDisponibles();

    // 6) Devolver el vehículo alquilado.
    std::cout << "\nDevolviendo el auto ABC123...\n";
    sistema.devolverVehiculo("ABC123");

    std::cout << "\n";
    sistema.mostrarDisponibles();

    return 0;
}
