#ifndef BICICLETA_H
#define BICICLETA_H

#include "Vehiculo.h"

/**
 * @class Bicicleta
 * @brief Vehículo de tipo bicicleta, derivado de Vehiculo.
 *
 * Agrega el tipo de bicicleta (montaña, ruta, urbana) a los atributos
 * comunes heredados (marca, modelo, placa, disponibilidad).
 */
class Bicicleta : public Vehiculo {
public:
    /**
     * @brief Construye una bicicleta.
     * @param marca  Marca de la bicicleta.
     * @param modelo Modelo de la bicicleta.
     * @param placa  Placa o código identificador de la bicicleta.
     * @param tipo   Tipo de bicicleta (p. ej. "montaña", "ruta", "urbana").
     */
    Bicicleta(const std::string& marca, const std::string& modelo, const std::string& placa,
               const std::string& tipo);

    /**
     * @brief Muestra en consola los datos de la bicicleta, incluyendo
     *        su tipo.
     */
    void mostrarInformacion() const override;

    /** @brief Devuelve el tipo de bicicleta. */
    std::string getTipo() const;

private:
    std::string tipo_;
};

#endif // BICICLETA_H
