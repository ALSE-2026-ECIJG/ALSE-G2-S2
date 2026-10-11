#ifndef CARRITO_COMPRAS_H
#define CARRITO_COMPRAS_H
#include <vector>
#include "ItemCarrito.h"
using namespace std;
class CarritoCompras {
private:
    vector<ItemCarrito> items;
public:
    bool agregarProducto(Producto* producto, int cantidad);
    bool eliminarProducto(string nombre);
    double calcularTotal();
    void mostrarCarrito();
};
#endif
