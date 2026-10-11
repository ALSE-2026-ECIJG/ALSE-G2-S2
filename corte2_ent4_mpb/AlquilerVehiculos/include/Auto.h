#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

/**
 * @class Auto
 * @brief Vehículo de tipo automóvil, derivado de Vehiculo.
 *
 * Agrega la capacidad de pasajeros a los atributos comunes heredados
 * (marca, modelo, placa, disponibilidad).
 */
class Auto : public Vehiculo {
public:
    /**
     * @brief Construye un auto.
     * @param marca             Marca del auto.
     * @param modelo            Modelo del auto.
     * @param placa             Placa del auto.
     * @param capacidadPasajeros Número máximo de pasajeros que admite.
     */
    Auto(const std::string& marca, const std::string& modelo, const std::string& placa,
         int capacidadPasajeros);

    /**
     * @brief Muestra en consola los datos del auto, incluyendo su
     *        capacidad de pasajeros.
     */
    void mostrarInformacion() const override;

    /** @brief Devuelve la capacidad de pasajeros del auto. */
    int getCapacidadPasajeros() const;

private:
    int capacidadPasajeros_;
};

#endif // AUTO_H
