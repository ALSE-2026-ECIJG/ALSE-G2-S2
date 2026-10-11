#include "Producto.h"
#include <stdexcept>

Producto::Producto(const std::string& nombre, double precio, int stock)
    : nombre(nombre), precio(precio), stock(stock) {
    if (precio < 0 || stock < 0) {
        throw std::invalid_argument(
            "El precio y el stock no pueden ser negativos."
        );
    }
}

std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

int Producto::getStock() const {
    return stock;
}

bool Producto::reducirStock(int cantidad) {
    if (cantidad <= 0 || cantidad > stock) {
        return false;
    }

    stock -= cantidad;
    return true;
}

void Producto::aumentarStock(int cantidad) {
    if (cantidad > 0) {
        stock += cantidad;
    }
}
