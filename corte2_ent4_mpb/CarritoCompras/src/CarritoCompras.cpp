
#include "CarritoCompras.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

bool CarritoCompras::agregarProducto(
    Producto* producto, int cantidad) {

    if (producto == nullptr || cantidad <= 0) {
        return false;
    }

    // Buscar si el producto ya está en el carrito.
    auto it = std::find_if(
        items_.begin(), items_.end(),
        [producto](const ItemCarrito& item) {
            return item.getProducto() == producto;
        }
    );

    // Reservar las unidades antes de modificar el carrito.
    if (!producto->reducirStock(cantidad)) {
        std::cout << "Stock insuficiente para "
                  << producto->getNombre() << ".\n";
        return false;
    }

    if (it != items_.end()) {
        it->setCantidad(it->getCantidad() + cantidad);
    } else {
        items_.emplace_back(producto, cantidad);
    }

    return true;
}

bool CarritoCompras::eliminarProducto(
    const std::string& nombreProducto) {

    auto it = std::find_if(
        items_.begin(), items_.end(),
        [&nombreProducto](const ItemCarrito& item) {
            return item.getProducto()->getNombre()
                   == nombreProducto;
        }
    );

    if (it == items_.end()) {
        return false;
    }

    // Al eliminar un artículo, se libera la reserva.
    it->getProducto()->aumentarStock(it->getCantidad());

    items_.erase(it);
    return true;
}

double CarritoCompras::calcularTotal() const {
    double total = 0.0;

    for (const ItemCarrito& item : items_) {
        total += item.calcularSubtotal();
    }

    return total;
}

void CarritoCompras::mostrarCarrito() const {
    std::cout << "\n--- Carrito de compras ---\n";

    if (items_.empty()) {
        std::cout << "El carrito esta vacio.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);

    for (const ItemCarrito& item : items_) {
        std::cout << item.getCantidad() << " x "
                  << item.getProducto()->getNombre()
                  << " = $" << item.calcularSubtotal()
                  << '\n';
    }

    std::cout << "TOTAL: $" << calcularTotal() << '\n';
}

void CarritoCompras::vaciarCarrito() {
    // Cancelación: devolver todas las unidades reservadas.
    for (ItemCarrito& item : items_) {
        item.getProducto()->aumentarStock(item.getCantidad());
    }

    items_.clear();
}

void CarritoCompras::confirmarCompra() {
    // Venta confirmada: NO devolver las unidades al inventario.
    items_.clear();
}

const std::vector<ItemCarrito>&
CarritoCompras::getItems() const {
    return items_;
}

const std::vector<ItemCarrito>& CarritoCompras::getItems() const {
    return items_;
}
