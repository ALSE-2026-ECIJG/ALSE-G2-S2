#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H

#include <memory>
#include <string>
#include <vector>

#include "Vehiculo.h"

/**
 * @class SistemaAlquiler
 * @brief Administra una colección heterogénea de vehículos (autos y
 *        bicicletas) y las operaciones de alquiler sobre ellos.
 *
 * Guarda los vehículos como std::unique_ptr<Vehiculo> para poder
 * almacenar en una misma colección objetos de distintas clases
 * derivadas (Auto, Bicicleta, o cualquier otra que se agregue en el
 * futuro) y aprovechar el polimorfismo: al llamar a
 * vehiculo->mostrarInformacion(), se ejecuta automáticamente la
 * versión correspondiente al tipo real del objeto.
 */
class SistemaAlquiler {
public:
    /**
     * @brief Registra un nuevo vehículo en el sistema.
     * @param vehiculo Puntero inteligente al vehículo a registrar. El
     *                 sistema toma posesión del objeto (se mueve con
     *                 std::move).
     */
    void registrarVehiculo(std::unique_ptr<Vehiculo> vehiculo);

    /**
     * @brief Alquila el vehículo identificado por su placa, si existe
     *        y está disponible.
     * @param placa Placa del vehículo a alquilar.
     * @return true si se alquiló correctamente; false si no se
     *         encontró el vehículo o ya estaba alquilado.
     */
    bool alquilarVehiculo(const std::string& placa);

    /**
     * @brief Devuelve (termina el alquiler de) el vehículo identificado
     *        por su placa.
     * @param placa Placa del vehículo a devolver.
     * @return true si se encontró el vehículo y se marcó como
     *         disponible; false si no existe un vehículo con esa placa.
     */
    bool devolverVehiculo(const std::string& placa);

    /**
     * @brief Imprime en consola los vehículos actualmente disponibles.
     */
    void mostrarDisponibles() const;

    /**
     * @brief Imprime en consola todos los vehículos registrados.
     */
    void mostrarTodos() const;

    /**
     * @brief Cantidad total de vehículos registrados.
     */
    std::size_t cantidadVehiculos() const;

private:
    std::vector<std::unique_ptr<Vehiculo>> vehiculos_;

    /**
     * @brief Busca un vehículo por placa dentro de la colección.
     * @param placa Placa a buscar.
     * @return Puntero crudo al vehículo encontrado, o nullptr si no
     *         existe ningún vehículo con esa placa.
     *
     * Devuelve un puntero crudo (no propietario) porque solo se usa
     * para leer/modificar el objeto ya existente; la propiedad del
     * objeto sigue siendo del vector vehiculos_.
     */
    Vehiculo* buscarPorPlaca(const std::string& placa) const;
};

#endif // SISTEMA_ALQUILER_H
