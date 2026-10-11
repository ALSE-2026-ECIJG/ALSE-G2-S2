#ifndef ITEM_CARRITO_H
#define ITEM_CARRITO_H

#include "Producto.h"

/**
 * @class ItemCarrito
 * @brief Representa un producto dentro del carrito, junto con la
 *        cantidad deseada de ese producto.
 *
 * Guarda un PUNTERO al Producto (no una copia), para que siempre
 * refleje los datos reales del catálogo (p. ej. si el precio del
 * producto cambiara, el ítem del carrito vería el precio actualizado
 * en vez de quedarse con un precio obsoleto). El ItemCarrito NO es
 * dueño del Producto: quien lo crea y lo destruye es el catálogo o
 * quien administre el inventario, no el carrito.
 */
class ItemCarrito {
public:
    /**
     * @brief Construye un ítem de carrito.
     * @param producto Puntero al producto del catálogo (no se
     *                 transfiere la propiedad; el carrito solo lo
     *                 referencia).
     * @param cantidad Cantidad deseada de ese producto.
     */
    ItemCarrito(Producto* producto, int cantidad);

    /** @brief Devuelve el puntero al producto referenciado. */
    Producto* getProducto() const;

    /** @brief Devuelve la cantidad de este ítem. */
    int getCantidad() const;

    /**
     * @brief Cambia la cantidad de este ítem.
     * @param cantidad Nueva cantidad (debe ser mayor que 0).
     */
    void setCantidad(int cantidad);

    /**
     * @brief Calcula el subtotal de este ítem (precio del producto
     *        multiplicado por la cantidad).
     * @return El subtotal.
     */
    double calcularSubtotal() const;

private:
    Producto* producto_;
    int cantidad_;
};

#endif // ITEM_CARRITO_H
