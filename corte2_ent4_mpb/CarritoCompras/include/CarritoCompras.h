#ifndef CARRITO_COMPRAS_H
#define CARRITO_COMPRAS_H

#include <string>
#include <vector>

#include "ItemCarrito.h"
#include "Producto.h"

/**
 * @class CarritoCompras
 * @brief Administra la colección de ItemCarrito de una compra en curso.
 *
 * Al agregar un producto, intenta reservar su stock (Producto::
 * reducirStock); si no hay suficiente stock, no se agrega. Al eliminar
 * un producto del carrito, se le devuelve el stock reservado.
 */
class CarritoCompras {
public:
    /**
     * @brief Agrega un producto al carrito con la cantidad indicada.
     *
     * Si el producto ya está en el carrito, aumenta su cantidad en
     * lugar de crear un segundo ítem duplicado. Antes de agregar,
     * verifica que haya stock suficiente; si no lo hay, no se realiza
     * ningún cambio.
     *
     * @param producto Puntero al producto del catálogo a agregar.
     * @param cantidad Cantidad deseada.
     * @return true si se agregó correctamente; false si no había
     *         stock suficiente.
     */
    bool agregarProducto(Producto* producto, int cantidad);

    /**
     * @brief Elimina del carrito todas las unidades de un producto,
     *        devolviendo esas unidades al stock del producto.
     * @param nombreProducto Nombre del producto a eliminar.
     * @return true si el producto estaba en el carrito y se eliminó;
     *         false si no se encontró.
     */
    bool eliminarProducto(const std::string& nombreProducto);

    /**
     * @brief Calcula el total a pagar por todos los ítems del carrito.
     * @return La suma de los subtotales de cada ítem.
     */
    double calcularTotal() const;

    /**
     * @brief Imprime en consola el contenido actual del carrito.
     */
    void mostrarCarrito() const;

    /**
     * @brief Vacía el carrito, devolviendo el stock reservado de cada
     *        ítem a sus respectivos productos.
     */
    void vaciarCarrito();

    /** @brief Acceso de solo lectura a los ítems del carrito. */
    const std::vector<ItemCarrito>& getItems() const;

private:
    std::vector<ItemCarrito> items_;
};

#endif // CARRITO_COMPRAS_H
