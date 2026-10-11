
#include "Usuario.h"

#include <iomanip>
#include <iostream>
#include <sstream>

Usuario::Usuario(const std::string& nombre)
    : nombre_(nombre) {
}

std::string Usuario::getNombre() const {
    return nombre_;
}

void Usuario::agregarCompraAlHistorial(
    CarritoCompras& carrito) {

    if (carrito.getItems().empty()) {
        std::cout << "El carrito esta vacio. "
                  << "No hay compra que registrar.\n";
        return;
    }

    // Guardar una copia del detalle antes de limpiar el carrito.
    std::ostringstream detalle;
    bool primero = true;

    for (const ItemCarrito& item : carrito.getItems()) {
        if (!primero) {
            detalle << ", ";
        }

        detalle << item.getCantidad() << "x "
                << item.getProducto()->getNombre();

        primero = false;
    }

    double total = carrito.calcularTotal();

    // Guardar la compra en el historial.
    historial_.push_back({detalle.str(), total});

    // Confirmar la venta sin restaurar el inventario.
    carrito.confirmarCompra();

    std::cout << "Compra confirmada correctamente.\n";
    std::cout << "Total pagado: $" << std::fixed
              << std::setprecision(2) << total << '\n';
}

void Usuario::mostrarHistorial() const {
    std::cout << "\n--- Historial de compras de "
              << nombre_ << " ---\n";

    if (historial_.empty()) {
        std::cout << "No hay compras registradas.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);

    int numero = 1;

    for (const RegistroCompra& compra : historial_) {
        std::cout << numero++ << ". "
                  << compra.detalle
                  << " -> Total: $" << compra.total << '\n';
    }
}

const std::vector<RegistroCompra>&
Usuario::getHistorial() const {
    return historial_;
}
