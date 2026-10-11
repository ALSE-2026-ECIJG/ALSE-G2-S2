#ifndef ITEM_CARRITO_H
#define ITEM_CARRITO_H
#include "Producto.h"
class ItemCarrito {
private:
    Producto* producto;
    int cantidad;
public:
    ItemCarrito(Producto* producto, int cantidad);
    Producto* getProducto();
    int getCantidad();
    void cambiarCantidad(int cantidad);
    double subtotal();
};
#endif
