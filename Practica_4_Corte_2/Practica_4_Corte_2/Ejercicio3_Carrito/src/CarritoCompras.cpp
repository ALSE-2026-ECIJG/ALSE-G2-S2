#include "CarritoCompras.h"
#include <iostream>
using namespace std;
bool CarritoCompras::agregarProducto(Producto* producto, int cantidad) {
    if (cantidad <= 0 || cantidad > producto->getStock()) {
        cout << "Cantidad no valida o stock insuficiente.\n";
        return false;
    }
    for (ItemCarrito &item : items) {
        if (item.getProducto()->getNombre() == producto->getNombre()) {
            int nueva = item.getCantidad() + cantidad;
            if (nueva > producto->getStock()) {
                cout << "No hay suficiente stock.\n";
                return false;
            }
            item.cambiarCantidad(nueva);
            return true;
        }
    }
    items.push_back(ItemCarrito(producto, cantidad));
    return true;
}
bool CarritoCompras::eliminarProducto(string nombre) {
    for (int i = 0; i < (int)items.size(); i++) {
        if (items[i].getProducto()->getNombre() == nombre) {
            items.erase(items.begin() + i);
            return true;
        }
    }
    return false;
}
double CarritoCompras::calcularTotal() {
    double total = 0;
    for (ItemCarrito item : items) total += item.subtotal();
    return total;
}
void CarritoCompras::mostrarCarrito() {
    if (items.empty()) cout << "El carrito esta vacio.\n";
    for (ItemCarrito item : items) {
        cout << item.getProducto()->getNombre() << " x " << item.getCantidad()
             << " = $" << item.subtotal() << endl;
    }
    cout << "Total: $" << calcularTotal() << endl;
}
