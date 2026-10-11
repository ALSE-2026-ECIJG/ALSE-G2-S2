
#ifndef CARRITO_COMPRAS_H
#define CARRITO_COMPRAS_H

#include <string>
#include <vector>
#include "ItemCarrito.h"
#include "Producto.h"

class CarritoCompras {
public:
    bool agregarProducto(Producto* producto, int cantidad);

    bool eliminarProducto(const std::string& nombreProducto);

    double calcularTotal() const;

    void mostrarCarrito() const;

    // Cancela el carrito y devuelve las unidades al inventario.
    void vaciarCarrito();

    // Confirma la compra y elimina los artículos sin devolver stock.
    void confirmarCompra();

    const std::vector<ItemCarrito>& getItems() const;

private:
    std::vector<ItemCarrito> items_;
};

#endif

    std::vector<ItemCarrito> items_;
};

#endif // CARRITO_COMPRAS_H
