#include "Usuario.h"

#include <iomanip>
#include <iostream>
#include <sstream>

Usuario::Usuario(const std::string& nombre) : nombre_(nombre) {
}

std::string Usuario::getNombre() const {
    return nombre_;
}

void Usuario::agregarCompraAlHistorial(CarritoCompras& carrito) {
    if (carrito.getItems().empty()) {
        std::cout << "El carrito está vacío; no hay compra que registrar.\n";
        return;
    }

    // Construimos el texto descriptivo ANTES de vaciar el carrito,
    // recorriendo sus ítems actuales.
    std::ostringstream detalle;
    bool primero = true;
    for (const ItemCarrito& item : carrito.getItems()) {
        if (!primero) {
            detalle << ", ";
        }
        detalle << item.getCantidad() << "x " << item.getProducto()->getNombre();
        primero = false;
    }

    RegistroCompra registro{detalle.str(), carrito.calcularTotal()};
    historial_.push_back(registro);

    // Ahora sí, vaciamos el carrito (esto además devuelve el stock
    // reservado... en un sistema real, aquí en cambio se confirmaría
    // la venta y el stock NO se devolvería; lo dejamos así para
    // mantener el ejemplo simple -- ver sección de mejoras).
    carrito.vaciarCarrito();
}

void Usuario::mostrarHistorial() const {
    std::cout << "--- Historial de compras de " << nombre_ << " ---\n";

    if (historial_.empty()) {
        std::cout << "  (Sin compras registradas)\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    int numero = 1;
    for (const RegistroCompra& compra : historial_) {
        std::cout << "  " << numero << ". " << compra.detalle << " -> Total: $" << compra.total
                   << "\n";
        ++numero;
    }
}

const std::vector<RegistroCompra>& Usuario::getHistorial() const {
    return historial_;
}
