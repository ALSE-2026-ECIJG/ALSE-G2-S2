#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

#include "CarritoCompras.h"

/**
 * @struct RegistroCompra
 * @brief Snapshot (copia fija) de una compra ya realizada.
 *
 * Se guarda como texto descriptivo y total pagado, en lugar de
 * guardar el CarritoCompras original, porque el carrito se vacía
 * después de cada compra (ver CarritoCompras::vaciarCarrito). Si el
 * historial guardara el carrito en sí, el registro quedaría vacío
 * tan pronto como el carrito se reutilizara para la siguiente compra.
 */
struct RegistroCompra {
    std::string detalle; ///< Descripción legible de los productos comprados.
    double total;        ///< Total pagado en esa compra.
};

/**
 * @class Usuario
 * @brief Representa un usuario de la tienda y su historial de compras.
 */
class Usuario {
public:
    /**
     * @brief Construye un usuario.
     * @param nombre Nombre del usuario.
     */
    explicit Usuario(const std::string& nombre);

    /** @brief Devuelve el nombre del usuario. */
    std::string getNombre() const;

    /**
     * @brief Registra en el historial del usuario la compra actual de
     *        un carrito, y luego vacía ese carrito.
     *
     * Toma una "foto" del contenido del carrito (qué se compró y el
     * total) antes de vaciarlo, para que el historial conserve esa
     * información aunque el carrito se reutilice después.
     *
     * @param carrito Carrito cuya compra se va a confirmar y registrar.
     */
    void agregarCompraAlHistorial(CarritoCompras& carrito);

    /**
     * @brief Imprime en consola el historial de compras del usuario.
     */
    void mostrarHistorial() const;

    /** @brief Acceso de solo lectura al historial de compras. */
    const std::vector<RegistroCompra>& getHistorial() const;

private:
    std::string nombre_;
    std::vector<RegistroCompra> historial_;
};

#endif // USUARIO_H
