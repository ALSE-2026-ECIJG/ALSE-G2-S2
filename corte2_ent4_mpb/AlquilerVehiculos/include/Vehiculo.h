#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

/**
 * @class Vehiculo
 * @brief Clase base abstracta para todos los vehículos del sistema de alquiler.
 *
 * Es abstracta porque mostrarInformacion() es una función virtual pura
 * (= 0): no tiene cuerpo en Vehiculo, así que esta clase no se puede
 * instanciar directamente (no se puede crear un "Vehiculo" genérico,
 * solo un Auto o una Bicicleta concretos). Cada clase derivada está
 * obligada a implementar su propia versión.
 */
class Vehiculo {
public:
    /**
     * @brief Construye un vehículo con sus datos básicos.
     * @param marca  Marca del vehículo.
     * @param modelo Modelo del vehículo.
     * @param placa  Placa (identificador único) del vehículo.
     *
     * El vehículo se crea disponible (disponible = true) por defecto.
     */
    Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa);

    /**
     * @brief Destructor virtual.
     *
     * Es obligatorio declararlo virtual en una clase base que se usará
     * polimórficamente (a través de punteros/referencias a Vehiculo),
     * para que al destruir un Auto o Bicicleta a través de un
     * Vehiculo* se llame también al destructor de la clase derivada.
     */
    virtual ~Vehiculo() = default;

    // --- Getters ---

    /** @brief Devuelve la marca del vehículo. */
    std::string getMarca() const;

    /** @brief Devuelve el modelo del vehículo. */
    std::string getModelo() const;

    /** @brief Devuelve la placa del vehículo. */
    std::string getPlaca() const;

    /** @brief Indica si el vehículo está disponible para alquilar. */
    bool isDisponible() const;

    // --- Operaciones de alquiler ---

    /** @brief Marca el vehículo como alquilado (no disponible). */
    void alquilar();

    /** @brief Marca el vehículo como devuelto (disponible de nuevo). */
    void devolver();

    /**
     * @brief Muestra la información del vehículo en consola.
     *
     * Función virtual pura: cada clase derivada (Auto, Bicicleta) debe
     * proporcionar su propia implementación, agregando sus atributos
     * específicos (capacidadPasajeros, tipo, etc.) a los datos comunes.
     */
    virtual void mostrarInformacion() const = 0;

protected:
    // 'protected' (en vez de 'private') permite que las clases
    // derivadas accedan directamente a estos atributos al construir
    // su propio mostrarInformacion(), sin necesitar getters para ello.
    std::string marca_;
    std::string modelo_;
    std::string placa_;
    bool disponible_;
};

#endif // VEHICULO_H
