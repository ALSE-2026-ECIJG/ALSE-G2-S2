#include "Producto.h"

Producto::Producto(const std::string& nombre, double precio, int stock)
    : nombre_(nombre), precio_(precio), stock_(stock) {
}

std::string Producto::getNombre() const {
    return nombre_;
}

double Producto::getPrecio() const {
    return precio_;
}

int Producto::getStock() const {
    return stock_;
}

bool Producto::reducirStock(int cantidad) {
    if (cantidad <= 0 || cantidad > stock_) {
        return false; // no hay suficiente stock (o cantidad inválida)
    }
    stock_ -= cantidad;
    return true;
}

void Producto::aumentarStock(int cantidad) {
    if (cantidad > 0) {
        stock_ += cantidad;
    }
}
