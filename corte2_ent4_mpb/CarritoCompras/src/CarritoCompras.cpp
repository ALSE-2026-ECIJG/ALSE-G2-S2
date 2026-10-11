#include "CarritoCompras.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

bool CarritoCompras::agregarProducto(Producto* producto, int cantidad) {
    if (producto == nullptr || cantidad <= 0) {
        return false;
    }

    // ¿Ya está este producto en el carrito? Si es así, solo aumentamos
    // su cantidad en vez de crear un ItemCarrito duplicado.
    auto it = std::find_if(items_.begin(), items_.end(), [producto](const ItemCarrito& item) {
        return item.getProducto() == producto;
    });

    // Intentamos reservar el stock ANTES de modificar el carrito; si no
    // hay suficiente, reducirStock devuelve false y no cambia nada.
    if (!producto->reducirStock(cantidad)) {
        std::cout << "No hay suficiente stock de \"" << producto->getNombre()
                   << "\" (disponible: " << producto->getStock() << ").\n";
        return false;
    }

    if (it != items_.end()) {
        it->setCantidad(it->getCantidad() + cantidad);
    } else {
        items_.emplace_back(producto, cantidad);
    }
    return true;
}

bool CarritoCompras::eliminarProducto(const std::string& nombreProducto) {
    auto it = std::find_if(items_.begin(), items_.end(), [&nombreProducto](const ItemCarrito& item) {
        return item.getProducto()->getNombre() == nombreProducto;
    });

    if (it == items_.end()) {
        return false; // no estaba en el carrito
    }

    // Devolvemos al stock las unidades que este ítem tenía reservadas.
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
    std::cout << "--- Carrito de compras ---\n";

    if (items_.empty()) {
        std::cout << "  (El carrito está vacío)\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    for (const ItemCarrito& item : items_) {
        std::cout << "  " << item.getCantidad() << " x " << item.getProducto()->getNombre()
                   << " @ $" << item.getProducto()->getPrecio() << " = $"
                   << item.calcularSubtotal() << "\n";
    }
    std::cout << "  TOTAL: $" << calcularTotal() << "\n";
}

void CarritoCompras::vaciarCarrito() {
    for (ItemCarrito& item : items_) {
        item.getProducto()->aumentarStock(item.getCantidad());
    }
    items_.clear();
}

const std::vector<ItemCarrito>& CarritoCompras::getItems() const {
    return items_;
}
