#include "ItemCarrito.h"
ItemCarrito::ItemCarrito(Producto* producto, int cantidad) {
    this->producto = producto; this->cantidad = cantidad;
}
Producto* ItemCarrito::getProducto() { return producto; }
int ItemCarrito::getCantidad() { return cantidad; }
void ItemCarrito::cambiarCantidad(int cantidad) { this->cantidad = cantidad; }
double ItemCarrito::subtotal() { return producto->getPrecio() * cantidad; }
